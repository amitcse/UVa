#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int dp[1001][1001];
int main()
{
	int t;
	geti(t);
	char str[1001];
	gets(str);
	while(t--)
	{
	    gets(str);

        int len = strlen(str),i,j,k,p,q;
        for(i=0;i<len;i++)
        {
            for(j=0;j<i;j++)
            dp[i][j] = 0;
            dp[i][j] = 1;
        }

        for(i=len-2;i>=0;i--)
        {
            p = i;
            q = len-1;
            for(j=i;j>=0;j--)
            {
                if(str[p]==str[q])
                dp[p][q] = dp[p+1][q-1]+2;
                else
                dp[p][q] = max(dp[p][q-1],dp[p+1][q]);
                p--;q--;
            }
        }
        cout<<dp[0][len-1]<<endl;
        /*for(i=0;i<len;i++)
        {
            for(j=0;j<len;j++)
            cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/
	}
	return 0;
}
