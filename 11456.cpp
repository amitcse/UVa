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
int arr[3000],lis[3000],lds[3000];
int main()
{
	int t,n,i,j,max;
	geti(t);
	while(t--)
	{
	    cin>>n;
	    rep(i,0,n)
	    {
	        cin>>arr[i];
	        lis[i] = 1;
	        lds[i] = 1;
	    }

	    for(i=n-2;i>=0;i--)
	    {
	        for(j=n-1;j>i;j--)
	        {
	            if(arr[i]>arr[j] && lis[i]<lis[j]+1)
	            {
	                lis[i] = lis[j]+1;
	            }
	        }
	        for(j=n-1;j>i;j--)
	        {
	            if(arr[i]<arr[j] && lds[i]<lds[j]+1)
	            {
	                lds[i] = lds[j]+1;
	            }
	        }
	    }
	    max = 0;
	    for(i=0;i<n;i++)
	    {
	        if((lds[i]+lis[i]-1) > max)
	        max = lis[i]+lds[i]-1;
	    }
	    cout<<max<<endl;
	}
	return 0;
}
