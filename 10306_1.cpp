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
#define INF 1<<30
using namespace std;
int conventional[41];
int infotech[41];
int coinsval[301][301];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
	    int n,s,i,j,k,ans,sq;
	    scanf("%d %d",&n,&s);
	    pair<int,int> coins[n+1];
	    for(i=0;i<n;i++)
	    {
	        scanf("%d %d",&conventional[i],&infotech[i]);
	    }

	    for(i=0;i<=s;i++)
	    for(j=0;j<=s;j++)
	    coinsval[i][j] = INF;

	    coinsval[0][0] = 0;
	    for(i=0;i<n;i++)
	    {
	        for(j=conventional[i];j<=s;j++)
	        {
	            for(k=infotech[i];k<=s;k++)
	            {
	                coinsval[j][k] = min(coinsval[j][k], 1+coinsval[j-conventional[i]][k-infotech[i]]);
	            }
	        }
	    }
	    ans = INF;
	    sq = s*s;
	    for(i=0;i<=s;i++)
	    {
	        for(j=0;j<=s;j++)
	        {
	            if((i*i + j*j)==sq)
	            ans = min(ans, coinsval[i][j]);
	        }
	    }
	    if(ans==INF)
	    printf("not possible\n");
	    else
	    printf("%d\n",ans);
	}
	return 0;
}
