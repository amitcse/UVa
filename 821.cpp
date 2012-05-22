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
map<int,int> nodes;
int main()
{
	int x,y,i,j,k,cn = 0;
	while(scanf("%d %d",&x,&y) && x && y)
	{
	    cn++;
	    nodes.clear();
	    int cost[101][101];
	    for(i=0;i<101;i++)
	    for(j=0;j<101;j++)
	        cost[i][j] = i==j ? 0 : INF;

	    cost[x][y] = 1;
	    nodes[x] = 1;
	    nodes[y] = 1;
	    while(scanf("%d %d",&x,&y) && x && y)
	    {
	        cost[x][y] = 1;
	        nodes[x] = 1;
	        nodes[y] = 1;
	    }

	    for(k=0;k<101;k++)
	    {
	        for(i=0;i<101;i++)
	        {
	            for(j=0;j<101;j++)
	            cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
	        }
	    }
	    long long sum = 0;
	    for(i=1;i<101;i++)
	    {
	        for(j=1;j<101;j++)
	        if(cost[i][j]!=INF)
	        sum += cost[i][j];
	    }
	    int numnodes = nodes.size();
        int nodepair = numnodes*(numnodes-1);
	    float ans = (float)sum/nodepair;
	    printf("Case %d: average length between pages = %.3f clicks\n",cn,ans);
	}
	return 0;
}
