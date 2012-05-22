//bellman ford-- maximizing each path

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
vector<vector<int> > adj(101);
//bool isreachable(int, int);
//bool vis[101];
int main()
{
	int n=0;
	while(true)
	{
	    for(int i=0;i<=n;i++)
	    adj[i].clear();
	    scanf("%d",&n);
	    if(n==-1)
	    break;
	    int i,j,k,x,t,w;

	    for(i=1;i<=n;i++)
	    {
	        scanf("%d",&w);
	        adj[i].pb(w);
	        scanf("%d",&t);
	        while(t--)
	        {
	            scanf("%d",&x);
	            adj[i].pb(x);
	        }
	    }

	    /*for(i=1;i<=n;i++)
	    {
	        cout<<i<<"  ";
	        for(j=0;j<adj[i].size();j++)
            cout<<adj[i][j]<<" ";
            cout<<endl;
	    }*/

	    int d[n+1];
	    //int p[n+1];
	    for(i=0;i<=n;i++)
	    {
	        d[i] = -11111111;
	        //p[i] = -1;
	    }
	    d[1] = 100;
	    for(i=0;i<=19990;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            int sz = adj[j].size()-1;
	            for(k=1;k<=sz;k++)
	            {
	                int next = adj[j][k];
	                int next_cost = adj[adj[j][k]][0];
	                //cout<<"  "<<next<<" "<<next_cost<<" "<<d[next]<<" ";
	                if(( d[j] + next_cost) <= 0)
	                continue;
	                if(d[next] < (d[j] + next_cost))
	                {
	                    d[next] = d[j] + next_cost;
	                    //p[adj[j][k]] = j;
	                    //cout<<d[next]<<endl;
	                }
	            }
	            if(d[n]>0) break;
	        }
	    }
	    if(d[n]>0)
	    cout<<"winnable\n";
	    else
	    cout<<"hopeless\n";
	    //for(i=0;i<=n;i++)
	    //cout<<p[i]<<" ";
	    //cout<<endl;
	    /*int curr,flag = 0;
	    if(d[n]>0)
	    {
	        //cout<<"in if"<<endl;
	        //checking for positive loop
	        for(j=1;j<=n;j++)
	        {
	            int sz = adj[j].size()-1;
	            for(k=1;k<=sz;k++)
	            {
	                if(d[adj[j][k]] < (d[j] + adj[adj[j][k]][0]))
	                {
	                    flag = 1;
	                    break;
	                }
	            }
	            if(flag)
	            break;
	        }
	        if(flag)
	        cout<<"winnable\n"; //positive loop found
	        else
	        {
	            curr = n;
	            int flag1=0;
                while(p[curr]!=-1)
                {
                    curr = p[curr];
                    if(d[curr]<=0)
                    {
                        flag1 = 1;
                        break;
                    }
                }
                if(flag1)
                cout<<"hopeless\n";    //energy -ve somewhere in path
                else
                cout<<"winnable\n";
	        }
	    }
	    else   // energy 0 or negative in final room
	    {
	        flag = 0;
	        for(j=1;j<=n;j++)   //checking positive loop
	        {
	            int sz = adj[j].size()-1;
	            for(k=1;k<=sz;k++)
	            {
	                if(d[adj[j][k]] < (d[j] + adj[adj[j][k]][0]))
	                {
	                    flag = 1;
	                    break;
	                }
	            }
	            if(flag)
	            break;
	        }
	        if(flag)    //loop found
	        {
	            for(i=0;i<=n;i++)
	            vis[i] = false;

	            if(isreachable(j,n))    //if loop reachable to final room
	            {
	                for(i=0;i<=n;i++)
                    vis[i] = false;
                    if(isreachable(1,j))  //if loop reachable from start
	                cout<<"winnable\n";
	                else
	                cout<<"hopeless\n";
	            }
	            else
	            cout<<"hopeless\n";

	        }
	        else    //positive loop not found
	        cout<<"hopeless\n";
	    }*/
	}
	return 0;
}
/*
bool isreachable(int s, int t)
{
    if(s==t)
    return true;
    vis[s] = true;

    int size = adj[s].size()-1;
    int i;
    for(i=1;i<=size;i++)
    {
        if(vis[adj[s][i]]) continue;
        //cout<<adj[s][i]<<endl;
        if(isreachable(adj[s][i],t))
        return true;
    }
    return false;
}
*/
/*
6
0 1 2
-100 1 3
10 2 2 4
10 2 3 5
-100 1 6
0 0

5
0 1 4
100 1 5
-80 1 2
-90 1 3
0 0

*/
