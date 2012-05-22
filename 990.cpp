#include <iostream>
#include <cstdio>
#define geti(x) scanf("%d",&x)

using namespace std;
int d[1000], g[1000], ans[1000];
int dp[1000][1000];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int t,w;
	int tc=0;
	while(scanf("%d %d",&t,&w)!=EOF)
	{
	    if(tc) cout<<endl;
	    tc++;
	    int n,i,j,k=0;
	    geti(n);
	    //int d[n+1],g[n+1],ans[n];
	    //int dp[n+1][t+1];
	    for(i=1;i<=n;i++)
	    {
	        geti(d[i]);geti(g[i]);
	    }
	    for(i=0;i<=t;i++)
	    dp[0][i]=0;
	    for(i=0;i<=n;i++)
	    dp[i][0]=0;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=t;j++)
	        {
	            if(3*w*d[i]>j)
	            dp[i][j] = dp[i-1][j];
	            else
	            dp[i][j] = max(dp[i-1][j],dp[i-1][j-3*w*d[i]]+g[i]);
	        }
	    }
	    cout<<dp[n][t]<<endl;
	    /*for(i=0;i<=n;i++)
	    {
	        for(j=0;j<=t;j++)
	        cout<<dp[i][j]<<" ";
	        cout<<endl;
	    }*/
	    i--;
	    j--;
	    //cout<<i<<" "<<j<<endl;
	    while(j>=0 && i>0)
	    {
	        if(dp[i-1][j]!=dp[i][j])
	        {
	            //cout<<"i = "<<i<<" j= "<<j<<endl;
	            //cout<<dp[i-1][j]<<"  "<<dp[i][j]<<endl;
	            ans[k++]=i;
	            //cout<<i<<" taken ";
	            j = j-3*w*d[i];
	            i--;
	        }
	        else
	        {
	            //cout<<i<<" not taken ";
	            i--;
	        }
	    }
	    cout<<k<<endl;
	    //for(i=0;i<k;i++)
	    //cout<<ans[i]<<" ";
	    //cout<<endl;
        for(i=k-1;i>=0;i--)
        {
            cout<<d[ans[i]]<<" "<<g[ans[i]]<<endl;
        }
	}
	return 0;
}
