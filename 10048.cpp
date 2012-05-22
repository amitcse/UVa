// MiniMax Floyd Warshall

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INF 21474836

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
	int c,s,q,i,j,k,x,y,w,cn = 0;
	bool blank = false;
	while(scanf("%d %d %d",&c,&s,&q) && c && s && q)
	{
	    cn++;
	    int adj[c+1][c+1];
	    for(i=0;i<=c;i++)
	    for(j=0;j<=c;j++)
	    adj[i][j] = i==j ? 0 : INF;

	    for(i=0;i<s;i++)
	    {
	        scanf("%d %d %d",&x,&y,&w);
	        adj[x][y] = w;
	        adj[y][x] = w;
	    }

	    for(k=1;k<=c;k++)
	    for(i=1;i<=c;i++)
	    for(j=1;j<=c;j++)
	    adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
        if(blank)
        printf("\n");
        blank = true;
        printf("Case #%d\n",cn);
	    for(i=0;i<q;i++)
	    {
	        scanf("%d %d", &x, &y);
	        if(adj[x][y]==INF)
	        printf("no path\n");
	        else
	        printf("%d\n",adj[x][y]);
	    }
	}
	return 0;
}
