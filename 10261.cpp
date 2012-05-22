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

int main()
{
	int t;
	geti(t);
	while(t--)
	{
	    int n,i,j,k,x;
	    scanf("%d",&n);
	    n = n*100;
	    vector<int> v;
	    while(1)
	    {
	        scanf("%d",&x);
	        if(x==0)
	        break;
	        v.pb(x);
	    }
	    reverse(v.begin(), v.end());
	    int dp[v.size()+1][n+1][n+1];
	    char path[v.size()+1][n+1][n+1];
	    for(i=0;i<=n;i++)
	    for(j=0;j<=n;j++)
	    {
	        dp[0][i][j] = 0;
	        path[0][i][j] = 'x';
	    }

	    for(i=1;i<=v.size();i++)
	    {
	        for(j=0;j<=n;j++)
	        {
	            for(k=0;k<=n;k++)
	            {
	                if(v[i-1]>j && v[i-1]> k)
	                {
	                    dp[i][j][k] = 0;
	                    path[i][j][k] = 'x';
	                }
	                else if(v[i-1]>j)
	                {
	                    dp[i][j][k] = dp[i-1][j][k-v[i-1]] + 1;
	                    path[i][j][k] = 's';
	                }
	                else if(v[i-1]>k)
	                {
	                    dp[i][j][k] = dp[i-1][j-v[i-1]][k] + 1;
	                    path[i][j][k] = 'l';
	                }
	                else
	                {
	                    dp[i][j][k] = max(dp[i-1][j-v[i-1]][k], dp[i-1][j][k-v[i-1]]) + 1;
	                    if(dp[i-1][j-v[i-1]][k] > dp[i-1][j][k-v[i-1]])
	                    path[i][j][k] = 'l';
	                    else
	                    path[i][j][k] = 's';
	                }
	            }
	        }
	    }
	    cout<<dp[v.size()][n][n]<<endl;
	    vector<string> p;
	    i = v.size();
	    j = n;
	    k = n;
	    while(i>0)
	    {
	        if(path[i][j][k] == 'l')
	        {
                j = j-v[i-1]; i = i-1;
                p.pb("left");
	        }
	        else if(path[i][j][k] == 's')
	        {
	            k = k-v[i-1]; i = i-1;
	            p.pb("right");
	        }
	        else
	        {
	            i = i-1;
	            p.pb("leave");
	        }
	    }
	    //reverse(p.begin(), p.end());
	    for(i=0;i<p.size();i++)
	    cout<<p[i]<<endl;

	}
	return 0;
}
