#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INF 1<<30
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
	int m,n,t,temp, i;
	while(scanf("%d",&m)!=EOF)
	{
	    scanf("%d %d",&n,&t);
	    if(n<m)
	    {
	        temp = m;
	        m = n;
	        n = temp;
	    }
	    if(t<m && t<n)
	    {
	        printf("0 %d\n",t);
	        continue;
	    }
	    if((t%m)==0)
	    {
	        printf("%d\n",t/m);
	        continue;
	    }
	    if(t>m && t<n)
	    {
	        printf("%d",t/m);
	        if((t%m)>0)
	        printf(" %d\n",t%m);
	        else
	        printf("\n");
	        continue;
	    }


	     int dp[t+1];
	     int beer[t+1];
	     dp[0] = 0; beer[0] = 0;

	     for(i=1;i<m;i++)
	     {
	         dp[i] = 0;
	         beer[i] = i;
	     }
	     for(i=m;i<n;i++)
	     {
	         dp[i] = dp[i-m]+1;
	         beer[i] = beer[i-m];
	     }
	     for(i=n;i<=t;i++)
	     {
	         if(beer[i-m]==beer[i-n])
	         {
	             beer[i] = beer[i-m];
	             dp[i] = max(dp[i-m],dp[i-n])+1;
	         }
	         else if(beer[i-m] < beer[i-n])
	         {
	             beer[i] = beer[i-m];
	             dp[i] = dp[i-m] + 1;
	         }
	         else
	         {
	             beer[i] = beer[i-n];
	             dp[i] = dp[i-n] + 1;
	         }
	     }
	     /*for(i=0;i<=t;i++)
	     cout<<dp[i]<<" ";
	     cout<<endl;
	     for(i=0;i<=t;i++)
	     cout<<beer[i]<<" ";
	     cout<<endl;*/
	     printf("%d",dp[t]);
	     if(beer[t]==0)
	     printf("\n");
	     else
	     printf(" %d\n",beer[t]);

	}
	return 0;
}
