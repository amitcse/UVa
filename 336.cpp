#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int adj[100][100];
int vis[100];
int idx[100];
int ttl[100];
int nnode=1;

int bfs(int, int);

int find(int i)
{
    int j;
    for(j=1;j<nnode;j++)
        if(idx[j]==i)
            return j;
    return -1;
}
int add(int i)
{
    idx[nnode] = i;
    nnode++;
    return nnode-1;
}
void init()
{
    int i,j;
    for(i=0;i<nnode;i++)
    {
        vis[i] = 0;
        ttl[i] = -1;
    }
}

void refresh()
{
    int i,j;
    for(i=0;i<100;i++)
    {
        idx[i] = 0;
        for(j=0;j<100;j++)
        adj[i][j] = 0;
    }
    nnode = 1;
}
int main()
{
	int t,caseno=1;
	while(true)
	{
	    geti(t);
	    if(t==0)
	    break;
	    int a,b,i,j,p,q,k,node,TTL,ans;
	    refresh();
	    for(i=0;i<t;i++)
	    {
	        cin>>a>>b;
	        p = find(a);
	        if(p==-1)
	        p = add(a);
	        q = find(b);
	        if(q==-1)
	        q = add(b);
            k = adj[p][0];
            adj[p][k+1] = q;
            adj[p][0]++;
            k = adj[q][0];
            adj[q][k+1] = p;
            adj[q][0]++;
	    }
	    /*cout<<"nnode = "<<nnode<<endl;
        for(i=1;i<nnode;i++)
        {
            cout<<idx[i]<<" ";
        }
        cout<<endl;
        for(i=0;i<nnode;i++)
	    {
	        cout<<i<<" "<<adj[i][0]<<"  ";
	        for(j=1;j<=adj[i][0];j++)
	        cout<<adj[i][j]<<" ";
	        cout<<endl;
	    }
	    cout<<endl;*/
	    while(true)
	    {
	        cin>>node>>TTL;
	        if(node==0 && TTL==0)
	        break;
	        ans = bfs(node,TTL);
	        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",caseno,ans,node,TTL);
	        caseno++;
	    }
	}
	return 0;
}

int bfs(int node, int TTL)
{
    init();
    queue<int> q;
    int x,count=0,i,pos;
    x = find(node);
    if(x==-1)
    return count;
    vis[x] = 1;
    ttl[x] = 0;
    q.push(x);
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(ttl[x]<TTL && ttl[x]>=0){
        pos = adj[x][0];
        for(i=1;i<=pos;i++)
        {
            if(!vis[adj[x][i]])
            {
                vis[adj[x][i]] = 1;
                ttl[adj[x][i]] = ttl[x]+1;
                q.push(adj[x][i]);
            }
        }
        }
    }
    for(i=1;i<nnode;i++)
    {
        //cout<<vis[i]<<" ";
        if(!vis[i])
            count++;
    }
    /*cout<<endl;
            for(i=1;i<nnode;i++)
        {
            cout<<ttl[i]<<" ";
        }
        cout<<endl;
    */
    return count;
}
