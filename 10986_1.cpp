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
#define INFINITY 1<<30
using namespace std;

int d[20010];
int vis[20010]={0};

struct comp
{
    bool operator()(const pair<int,int> &p, const pair<int,int> &q)
    {
        return p.second>q.second;
    }
};

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int cases,cn=0;
	int n=0,m,s,t,i,j,x,next,next_cost;
	geti(cases);
	while(cases--)
	{
	    cn++;

        int u,v,w;
	    scanf("%d %d %d %d",&n,&m,&s,&t);
	    vector<vector<pair<int,int> > > adj(n);
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d %d",&u, &v, &w);
            adj[u].pb( make_pair(v,w) );
            adj[v].pb( make_pair(u,w) );
	    }

	    for(i=0;i<n;i++)
	    {
	        d[i] = INFINITY;
	        vis[i] = 0;
	    }
	    d[s] = 0;
	    //priority_queue<pair<int,int> > pq;
	    //vector<pair<int,int> > q;
	    priority_queue<pair<int,int>, vector<pair<int,int> >, comp > q;
	    //pair<int,int> p;
        //q.pb(make_pair(d[s],s));
        q.push(make_pair(s,d[s]));
	    //make_heap(q.begin(),q.end(),comp());
        x=-1;
        while(!q.empty())
        {
            x = q.top().first;
            if(x==t) break;
            q.pop();

            if(vis[x]) {continue;}

            int sz = (int)adj[x].size();

            for(i=0;i<sz;i++)
            {
                next = adj[x][i].first;
                next_cost = adj[x][i].second;

                if(vis[next]) continue;

                if(d[next] > (d[x]+next_cost))
                    {
                        d[next] = d[x]+next_cost;
                        q.push(make_pair(next,d[next]));
                    }
            }
            vis[x] = 1;
        }
        cout<<"Case #"<<cn<<": ";
        if(x!=t)
        cout<<"unreachable"<<endl;
        else
        cout<<d[x]<<endl;
	}
	return 0;
}
