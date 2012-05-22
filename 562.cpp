
#include <cstdio>
#define geti(x) scanf("%d",&x)
using namespace std;
int arr[150],dp[150][50000];
int main()
{
    int t;
    geti(t);
    while(t--)
    {
        int n,i,j,sum=0,max,ans;
        geti(n);
        //int arr[n+1];
        for(i=1;i<=n;i++)
        {
            geti(arr[i]);
            sum+=arr[i];
        }
        max = sum/2;
        //int dp[n+1][max+1];
        for(i=0;i<=max;i++)
        dp[0][i]=0;
        for(i=0;i<=n;i++)
        dp[i][0]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=max;j++)
            {
                if(arr[i]>j)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = (dp[i-1][j] > dp[i-1][j-arr[i]]+arr[i]) ? dp[i-1][j] : dp[i-1][j-arr[i]]+arr[i];
            }
        }
        //printf("%d\n",dp[n][max]);
        ans = sum - 2*dp[n][max];
        printf("%d\n",ans);
    }
    return 0;
}
