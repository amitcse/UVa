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

long long psum[600];
long long dp[600][600];
long long path[600][600];
long long arr[600];
void print_sol(long long, long long);

int main()
{
    freopen("in.txt","r",stdin);
	long long t;
	scanf("%lld",&t);
	while(t--)
	{
	    long long m,k,i,j,x;
	    long long tmp;
	    scanf("%lld %lld",&m,&k);
	    for(i=1;i<=m;i++)
	    scanf("%lld",&arr[i]);
        //reverse(arr,arr+m);
	    psum[0] = 0;
	    for(i=1;i<=m;i++)
	    psum[i] = psum[i-1]+arr[i];

	    for(i=1;i<=m;i++)
	    {
	        dp[i][1] = psum[i];
	        //path[i][1] = i;
	    }

	    for(i=1;i<=k;i++)
	    {
	        dp[1][i] = arr[1];
	        //path[1][i] = 1;
	    }

	    for(i=2;i<=m;i++)
	    {
	        for(j=2;j<=k;j++)
	        {
	            dp[i][j] = INF;
	            for(x=1;x<=i-1;x++)
	            {
	                tmp = max(dp[x][j-1], psum[i]-psum[x]);
	                if(dp[i][j] > tmp)
	                {
	                    dp[i][j] = tmp;
	                    path[i][j] = x;
	                }
	            }
	        }
	    }

	    for(i=1;i<=m;i++)
	    {
	        for(j=1;j<=k;j++)
	        cout<<dp[i][j]<<" ";
	        cout<<endl;
	    }
        cout<<endl;
        for(i=1;i<=m;i++)
	    {
	        for(j=1;j<=k;j++)
	        cout<<path[i][j]<<" ";
	        cout<<endl;
	    }

	    cout<<dp[m][k]<<endl;
	    print_sol(m,k);
	    cout<<endl;
	    print_sol(3,3);
	    cout<<endl;;
	    print_sol(2,3);
	    cout<<endl;
	    print_sol(2,2);
	}
	return 0;
}

void print_sol(long long m, long long k)
{
    if(k==1)
    {
        //cout<<arr[1];
        for(int i=1;i<=m;i++)
        cout<<" "<<arr[i];
    }
    else
    {
        print_sol(path[m][k],k-1);
        cout<<" /";
        for(int i=path[m][k]+1;i<=m;i++)
        cout<<" "<<arr[i];
    }
}
