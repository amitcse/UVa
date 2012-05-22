#include <cstdio>
#define get(x) scanf("%d",&x)

using namespace std;

int main()
{
    int t;
    get(t);
    while(t--)
    {
        int n,i,j;
        get(n);
        int p[n+1],w[n+1];
        for(i=1;i<=n;i++)
        scanf("%d %d",&p[i],&w[i]);
        int g,maxi;
        get(g);
        int family[g];
        get(family[0]);
        maxi = family[0];
        for(i=1;i<g;i++)
        {
            get(family[i]);
            maxi = maxi<family[i] ? family[i] : maxi;
        }
        int dp[n+1][maxi+1];
        for(i=0;i<=maxi;i++)
        dp[0][i]=0;
        for(i=0;i<=n;i++)
        dp[i][0]=0;

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=maxi;j++)
            {
                if(w[i]>j)
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = (dp[i-1][j] > dp[i-1][j-w[i]]+p[i]) ? dp[i-1][j] : dp[i-1][j-w[i]]+p[i];
            }
        }
        int ans = 0;
        for(i=0;i<g;i++)
        ans += dp[n][family[i]];
        printf("%d\n",ans);
    }
    return 0;
}
