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
#define INFINITY 1<<30
using namespace std;

int dp[1000][1000];

int main()
{
	int l,n,len,st,end,temp,x,i,j,k;
	while(1)
	{
	    scanf("%d",&l);
	    if(l==0)
	    break;

	    scanf("%d",&n);
	    int arr[n+2];
	    arr[0] = 0;
	    for(i=1;i<=n;i++)
	    scanf("%d",&arr[i]);
	    arr[n+1] = l;
        //cout<<"hello\n";
	    for(i=0;i<n+1;i++)
	    {
	        st = arr[i];
	        end = arr[i+1];
	        //cout<<"st= "<<st<<"end "<<end<<endl;
	        dp[st][end] = 0;
	    }
	    for(len=3;len<=n+2;len++)
	    {
	        for(i=0;i<=(n+2)-len;i++)
	        {
	            j = i+len-1;
	            st = arr[i];
	            end = arr[j];
	            //cout<<"st = "<<st<<" end = "<<end<<endl;
	            dp[st][end] = INFINITY;
	            for(k=i+1;k<j;k++)
	            {
	                temp = dp[st][arr[k]] + dp[arr[k]][end] + (end-st);
	                if(temp < dp[st][end])
	                {
	                    //cout<<"  at "<<arr[k]<<endl;
	                    dp[st][end] = temp;
	                }
	            }
	        }
	    }
	    printf("The minimum cutting is %d.\n",dp[arr[0]][arr[n+1]]);
	}
	return 0;
}
