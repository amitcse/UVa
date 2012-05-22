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

using namespace std;
int adj[210][210];
bool vis[210];
int color[210];
bool isbicolourable(int,int);
int main()
{
	int n,i,a,b,m;
	while(1)
	{
	    scanf("%d",&n);
	    if(n==0)
	    break;

	    for(i=0;i<n;i++)
	    {
	        adj[i][0] = 0;
	        vis[i] = false;
	        color[i] = -1;
	    }

	    scanf("%d",&m);
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d",&a,&b);
	        adj[a][++adj[a][0]] = b;
	        adj[b][++adj[b][0]] = a;
	    }
	    /*cout<<endl;
        for(i=0;i<n;i++)
        {
            int l = adj[i][0];
            for(int j=0;j<=l;j++)
            cout<<adj[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        */
	    if(isbicolourable(0,0))
	    printf("BICOLORABLE.\n");
	    else
	    printf("NOT BICOLORABLE.\n");
	}
	return 0;
}

bool isbicolourable(int node,int clr)
{
    if(vis[node] && color[node]==clr)
    {
        //cout<<" visited and same colord"<<endl;
        return true;
    }
    if(vis[node] && color[node]==clr^1)
    {
        //cout<<"vis and oppp color"<<endl;
        return false;
    }

    vis[node] = true;
    color[node] = clr;

    int len = adj[node][0],i;
    for(i=1;i<=len;i++)
    {
        //cout<<" node "<<adj[node][i]<<" to color"<<(clr^1)<<endl;
        if(!isbicolourable(adj[node][i],clr^1))
        return false;
    }
    return true;
}
