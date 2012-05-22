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
	int n,i,j,k,x,y,cn = 0;
	float dist;
	while(scanf("%d",&n) && n)
	{
	    cn++;
	    float minimax[n+1][n+1];
	    for(i=0;i<=n;i++)
	    for(j=0;j<=n;j++)
	    minimax[i][j] = i==j ? 0 : INF;

	    vector<pair<int,int> > nodes(n+1);
	    nodes.pb(mp(-1,-1));

	    for(i=1;i<=n;i++)
	    {
	        scanf("%d %d", &x,&y);
	        nodes[i] = mp(x,y);
	        for(j=1;j<i;j++)
	        {
	            dist = sqrt((x-nodes[j].first)*(x-nodes[j].first) + (y-nodes[j].second)*(y-nodes[j].second));
	            minimax[i][j] = dist;
	            minimax[j][i] = dist;
	        }
	    }
	    /*for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        cout<<minimax[i][j]<<" ";
	        cout<<endl;
	    }
        */
	    for(k=1;k<=n;k++)
	    for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
            minimax[i][j] = min(minimax[i][j], max(minimax[i][k], minimax[k][j]));
        printf("Scenario #%d\n",cn);
        printf("Frog Distance = %.3f\n",minimax[1][2]);
        printf("\n");
	}
	return 0;
}
