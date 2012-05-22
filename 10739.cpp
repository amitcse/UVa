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

int dp[1010][1010];
int main()
{
	int t,l,i,j,cn=0;
	geti(t);
	while(t--)
	{
        cn++;
	    char str[1010];
	    scanf("%s",&str);

	    int len = strlen(str);

	    for(i=0;i<len;i++)
	    {
	        dp[i][i] = 0;
	    }
	    for(i=0;i<len-1;i++)
	    {
	        dp[i][i+1] = (str[i]==str[i+1]) ? 0 : 1;
	    }
        int p,q;

	    for(l=3;l<=len;l++)
	    {
	        for(i=0;i<=len-l;i++)
	        {
	            j = i+l-1;
	            //cout<<i<<" "<<j<<" "<<str[i]<<" "<<str[j]<<endl;
	            if(str[i]==str[j])
	            dp[i][j] = dp[i+1][j-1];
	            else
	            dp[i][j] = min(min(dp[i+1][j],dp[i][j-1]),dp[i+1][j-1])+1;
	        }
	    }
	    /*for(i=0;i<len;i++)
	    {
	        for(j=0;j<len;j++)
	        cout<<dp[i][j]<<" ";
	        cout<<endl;
	    }*/
	    printf("Case %d: %d\n",cn,dp[0][len-1]);
	}
	return 0;
}
