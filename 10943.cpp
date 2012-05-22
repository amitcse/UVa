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

using namespace std;

int dp[101][101];

int main()
{
	int i,j,x;
	long long tmp;
	for(i=0;i<=100;i++)
	{
	    dp[1][i] = 1;
	    dp[i][0] = 1;
	}

	for(i=2;i<=100;i++)
	{
	    for(j=1;j<=100;j++)
	    {
	        tmp = 0;
	        for(x=0;x<=j;x++)
	        {
	            tmp += dp[i-1][j-x]%1000000;
	        }
	        dp[i][j] = tmp%1000000;
	    }
	}

	int n,k;
	while(scanf("%d %d",&n,&k))
	{
	    if(n==0 && k==0)
	    break;

	    cout<<dp[k][n]<<endl;
	}
	return 0;
}
