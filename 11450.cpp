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
int garments[30][30];
int dp[30][300];

int main()
{
	int t;
	geti(t);
	while(t--)
	{
	    int m,c,i,j,k,cost,s;
	    scanf("%d %d",&m,&c);
	    for(i=1;i<=c;i++)
	    {
	        scanf("%d",&s);
	        garments[i][0] = s;
	        for(j=1;j<=s;j++)
	        {
	            scanf("%d",&garments[i][j]);
	        }
	    }

	    memset(dp,-1,sizeof(dp));
	    for(i=0;i<=m;i++)
	    dp[0][i] = 0;

	    for(i=1;i<=c;i++)
	    {
	        for(j=1;j<=m;j++)
	        {
	            for(k=1;k<=garments[i][0];k++)
	            {
	                cost = garments[i][k];
	                if(dp[i][j] < (dp[i-1][j-cost]+cost) && dp[i-1][j-cost]!=-1 && cost<=j)
	                dp[i][j] = dp[i-1][j-cost] + cost;
	            }
	        }
	    }
	    if(dp[c][m]==-1)
	    printf("no solution\n");
	    else
	    printf("%d\n",dp[c][m]);
	}
	return 0;
}
