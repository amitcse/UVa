#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
string convI2S(int number)
{
    stringstream ss;
    ss << number;
    return ss.str();
}
int main()
{
	int c,n,i,j;
	while(scanf("%d",&c)!=EOF)
	{
	    scanf("%d",&n);
	    int arr[n+1];
	    for(i=1;i<=n;i++)
	    {
	        scanf("%d",&arr[i]);
	    }
	    int dp[n+1][c+1];
	    string path[n+1][c+1];
	    for(i=0;i<=c;i++)
	    {
	        dp[0][i] = 0;
	        path[0][i] = "";
	    }
	    for(i=0;i<=n;i++)
	    {
	        dp[i][0] = 0;
	        path[i][0] = "";
	    }
	    //  0/1 knapsack
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=c;j++)
	        {
	            //cout<<"j = "<<j<<"arr = "<<arr[i]<<endl;
	            if(arr[i]>j)
	            {
	                dp[i][j] = dp[i-1][j];
	                path[i][j] = path[i-1][j];
	            }
	            else
	            {
	                //cout<<"  else  "<<(dp[i-1][j-arr[i]]+arr[i])<<"  "<<dp[i-1][j]<<endl;
	                if((dp[i-1][j-arr[i]]+arr[i]) > dp[i-1][j])
	                {
	                    //cout<<"   taken  ";
	                    dp[i][j] = dp[i-1][j-arr[i]] + arr[i];
	                    path[i][j] = path[i-1][j-arr[i]]+convI2S(arr[i])+" ";
	                    //cout<<dp[i][j]<<endl;
	                }
	                else
	                {
	                    //cout<<"  not taken ";
	                    dp[i][j] = dp[i-1][j];
	                    path[i][j] = path[i-1][j];
	                    //cout<<dp[i][j]<<endl;
	                }
	            }
	        }
	    }

        cout<<path[n][c];
	    cout<<"sum:"<<dp[n][c]<<endl;

	}
	return 0;
}
