#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
map<string,int> m1;
map<int,string> m2;
vector<int> adj[50],adjr[50];
bool vis1[50],vis2[50];
//int start[50],fin[50];
vector<pair<int, int> > finish;
int tim;
int n;
void init()
{
    int i;
    for(i=0;i<=n;i++)
    {
        vis1[i] = false;
        vis2[i] = false;
        adj[i].clear();
        adjr[i].clear();
    }
    m1.clear();
    m2.clear();
    finish.clear();
    tim = 0;
}
void dfs1(int i)
{
    int len,k;
    if(vis1[i])
    return;
    vis1[i] = true;
    len = adj[i].size();
    for(k=0;k<len;k++)
    {
        if(!vis1[adj[i][k]])
        {
            //vis1[i] = true;
            //start[adj[i][k]] = ++tim;
            dfs1(adj[i][k]);
            //fin[adj[i][k]] = ++tim;
            finish.pb(make_pair(++tim,adj[i][k]));
        }
    }
}

void dfs2(int i)
{
    if(vis2[i])
    return;
    int len,k;
    vis2[i] = true;
    len = adjr[i].size();
    for(k=0;k<len;k++)
    {
        if(!vis2[adjr[i][k]])
        {
            cout<<", "<<m2[adjr[i][k]];
            //vis2[adjr[i][k]] = true;
            dfs2(adjr[i][k]);
        }
    }
}

bool myfunc(pair<int,int> i,pair<int,int> j)
{
    return i>j;
}
int main()
{
    int m,i,j,k,l,x,y,cnt=1;
    string s1,s2;
	while(true)
	{
	    init();
	    k=1;
	    cin>>n>>m;
	    if(n==0 && m==0)
	    break;
	    for(i=0;i<m;i++)
	    {
            cin>>s1>>s2;
            if(m1.find(s1)==m1.end())
            {
                m1[s1] = k;
                m2[k++] = s1;
            }
            if(m1.find(s2)==m1.end())
            {
                m1[s2] = k;
                m2[k++] = s2;
            }
            //cout<<m1[s1]<<" "<<m1[s2]<<endl;
            x = m1[s1];
            y = m1[s2];
            adj[x].pb(y);
            adjr[y].pb(x);
	    }
	    /*for(i=1;i<=n;i++)
	    {
	        cout<<i<<"  ";
	        for(j=0;j<adj[i].size();j++)
	        cout<<adj[i][j]<<" ";
	        cout<<endl;
	    }
        cout<<endl;
        */
	    for(i=1;i<=n;i++)
	    {
	        if(!vis1[i])
	        {
	            //start[i] = ++tim;
	            dfs1(i);
	            //fin[i] = ++tim;
	            finish.pb(make_pair(++tim,i));
	        }
	    }
	    sort(finish.begin(),finish.end(),myfunc);
	    /*for(i=1;i<=n;i++)
	    {
	        cout<<start[i]<<"  "<<fin[i]<<endl;
	    }
        cout<<endl;*/
	    /*for(i=1;i<=n;i++)
	    {
	        l = adj[i].size();
	        for(j=0;j<l;j++)
	        {
	            adjr[adj[i][j]].pb(i);
	        }
	    }*/
	    /*for(i=1;i<=n;i++)
	    {
	        cout<<i<<"  ";
	        for(j=0;j<adjr[i].size();j++)
	        cout<<adjr[i][j]<<" ";
	        cout<<endl;
	    }*/
	    if(cnt>1)
	    printf("\n");
	    printf("Calling circles for data set %d:\n",cnt);
	    cnt++;
	    for(i=0;i<n;i++)
	    {
	        if(!vis2[finish[i].second])
	        {
	            cout<<m2[finish[i].second];
	            dfs2(finish[i].second);
	            cout<<endl;
	        }
	    }
	}
	return 0;
}
