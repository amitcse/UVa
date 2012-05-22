#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INF 1<<30
using namespace std;
int parent[50];
struct node
{
    int n;
    vector<int> dim;
};
bool canNest(node, node, int);
void print_path(int);
int main()
{
    int k,n,i,j,x,next,p,sz;
    while(scanf("%d %d",&k,&n)!=EOF)
    {
        vector<node> v(k+1);
        for(i=1;i<=k;i++)
        {
            node temp;
            for(j=0;j<n;j++)
            {
                scanf("%d",&x);
                temp.dim.pb(x);
            }
            sort(temp.dim.begin(), temp.dim.end());
            v[i] = temp;
        }
        vector<int> adj[k+2];
        int indeg[50] = {0};
        int sorted[k+2];
        queue<int> q;
        for(i=1;i<=k;i++)
        {
            for(j=1;j<=k;j++)
            {
                if(i==j)
                continue;
                if(canNest(v[i],v[j],n))  // if i nests inside j
                {
                    adj[i].pb(j);
                    indeg[j]++;
                }
            }
        }
        for(i=1;i<=k;i++)  // supersource
        {
            if(indeg[i]==0)
            {
                adj[0].pb(i);
                indeg[i]++;
            }
        }
        for(i=1;i<=k;i++) //supersink
        {
            if(adj[i].size()==0)
            {
                adj[i].pb(k+1);
                indeg[k+1]++;
            }
        }
        /*cout<<endl;
        for(i=0;i<=k+1;i++)
        {
            for(j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<" ";
            cout<<endl;
        }
        cout<<"indeg = ";
        for(i=0;i<=k+1;i++)
        cout<<indeg[i]<<" ";
        cout<<endl;*/

        for(i=0;i<=k+1;i++)
        if(indeg[i]==0)
        q.push(i);
        p = 0;
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            sorted[p++] = x;
            sz = adj[x].size();
            for(i=0;i<sz;i++)
            {
                next = adj[x][i];
                indeg[next]--;
                if(indeg[next]==0)
                q.push(next);
            }
        }
        /*cout<<" p = "<<p<<endl;
        for(i=0;i<p;i++)
        cout<<"  "<<sorted[i];
        cout<<endl;*/

        int dist[k+2];
        memset(dist,INF,sizeof(dist));
        memset(parent,-1,sizeof(parent));
        dist[0] = 0;
        //longest path in DAG
        for(i=0;i<k+2;i++)
        {
            sz = adj[sorted[i]].size();
            for(j=0;j<sz;j++)
            {
                next = adj[sorted[i]][j];
                if(dist[next] > dist[sorted[i]]-1)
                {
                    dist[next] = dist[sorted[i]]-1;
                    parent[next] = sorted[i];
                }
            }
        }
        /*for(i=0;i<k+2;i++)
        cout<<dist[sorted[i]]<<" ";
        cout<<endl;*/
        int last = parent[k+1];
        printf("%d\n",-dist[parent[k+1]]);
        print_path(last);
        printf("\n");
    }
	return 0;
}

bool canNest(node a, node b, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(a.dim[i]>=b.dim[i])
        return false;
    }
    return true;
}
void print_path(int idx)
{
    if(parent[idx]==0)
    {
        printf("%d",idx);
        return;
    }
    print_path(parent[idx]);
    printf(" %d",idx);
}
