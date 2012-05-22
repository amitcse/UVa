#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <climits>
#include<functional>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INFINITY INT_MAX
using namespace std;

int d[20010];
int vis[20010]={0};
map<pair<int,int>, int> wt;
map<pair<int,int>, int>::iterator it;
vector<int> adj[20010];
vector<pair<int,int> >q;

struct comp
{
    bool operator()(const pair<int,int> &p, const pair<int,int> &q)
    {
        return p.first>q.first;
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int cases,cn=1;
	int n=0,m,s,t,i,j;
	geti(cases);
	while(cases--)
	{
	    wt.clear();
	    for(i=0;i<n;i++)
	    adj[i].clear();
	    q.clear();

        int u,v,w;
	    scanf("%d %d %d %d",&n,&m,&s,&t);
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d %d",&u, &v, &w);
            wt[make_pair(u,v)] = w;
            wt[make_pair(v,u)] = w;
            adj[u].pb(v);
            adj[v].pb(u);
	    }
	    /*for(i=0;i<n;i++)
	    {
	        for(j=0;j<adj[i].size();j++)
	        cout<<adj[i][j]<<" ";
	        cout<<endl;
	    }
	    for(it=wt.begin();it!=wt.end();it++)
	    {
	        cout<<it->second<<endl;
	    }*/
	    for(i=0;i<n;i++)
	    {
	        d[i] = INFINITY;
	        vis[i] = 0;
	    }
	    d[s] = 0;
	    //priority_queue<pair<int,int> > pq;
	    pair<int,int> p;
        q.pb(make_pair(d[s],s));
	    make_heap(q.begin(),q.end(),comp());
	    int x=-1;
        while(!q.empty())
        {
            p = q.front();
            x = p.second;
            //cout<<"extracted "<<x<<endl;
            if(x==t)
            break;
            pop_heap(q.begin(),q.end(),comp());
            q.pop_back();

            vis[x] = 1;
            int sz = adj[x].size();
            //cout<<" size "<<sz<<endl;
            for(i=0;i<sz;i++)
            {
                int next = adj[x][i];
                if(!vis[next])
                {
                    //cout<<"  node"<<next<<endl;
                    int next_cost = wt[pair<int,int>(x,next)];
                    //cout<<"   "<<next_cost<<endl;
                  if(d[next] > d[x]+next_cost)
                    {
                        //cout<<"  "<<d[next]<<endl;
                        d[adj[x][i]] = d[x]+next_cost;
                        //cout<<"  "<<d[next]<<endl;
                        q.pb(make_pair(d[next],next));
                    }
                }
            }
            make_heap(q.begin(),q.end(),comp());
        }
        cout<<"Case #"<<cn++<<": ";
        if(x!=t)
        cout<<"unreachable"<<endl;
        else
        cout<<d[x]<<endl;
	}
	return 0;
}
