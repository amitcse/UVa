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
#define INFINITY 1<<30
using namespace std;

bool airport[2010];
vector<int> adj[2010];
bool vis[2010];
int d[2010];
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
    bool blank = false;
	int cases,cn=0;
	geti(cases);
	while(cases--)
	{
	    cn++;
	    //if(blank)
	    //printf("\n");
	    //blank = true;

	    int n,m,k,x,y,p,i,q,len,next;
	    scanf("%d %d %d",&n,&m,&k);

	    for(i=0;i<=n;i++)
	    {
	        airport[i] = false;
	        adj[i].clear();
	    }

	    for(i=0;i<k;i++)
	    {
	        geti(x);
	        airport[x] = true;
	    }
	    for(i=0;i<m;i++)
	    {
	        geti(x);
	        geti(y);
	        adj[x].pb(y);
	        adj[y].pb(x);
	    }

	    geti(q);
	    printf("Case %d:\n",cn);
	    while(q--)
	    {
	        geti(x);
	        geti(y);
	        if(x==y)
	        {
	            printf("0\n");
                continue;
	        }
	        for(i=1;i<=n;i++)
	        {
	            d[i] = INFINITY;
	            vis[i] = false;
	        }
	        if(!airport[x])
	        d[x] = 1;
	        else
	        d[x] = 0;
	        priority_queue<pair<int,int>, vector<pair<int,int> >, comp > q;

	        q.push(make_pair(x,d[x]));

	        while(!q.empty())
	        {
	            p = q.top().first;
	            if(p==y)
	            break;
	            q.pop();
                if(vis[p]) continue;
	            len = (int)adj[p].size();
	            for(i=0;i<len;i++)
	            {
	                next = adj[p][i];

	                if(vis[next]) continue;

                    int dis = (airport[next]) ? 0 : 1;

                    if(d[next] > (d[p] + dis))
                    {
                        d[next] = d[p] + dis;
                        q.push(make_pair(next,d[next]));
                    }
	            }
	            vis[p] = true;
	        }
	        if(p!=y)
	        printf("-1\n");
	        else
	        {
	            //if(!airport[x]) d[y]++;
	            printf("%d\n",d[y]);
	        }
	    }
	    printf("\n");
	}
	return 0;
}
