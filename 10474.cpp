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
int arr[50000000],n;
int find(int);
int main()
{
	int q,i,pos,x,cn = 0;
	while(true)
	{
	    cn++;
	    scanf("%d %d",&n,&q);
	    if(n==0 && q==0)
	    break;

	    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
	    sort(arr,arr+n);
	    printf("CASE# %d:\n",cn);
	    while(q--)
	    {
	        scanf("%d",&x);
	        pos = find(x);
	        if(pos==-1)
	        printf("%d not found\n",x);
	        else
	        printf("%d found at %d\n",x,pos+1);
	    }
	}
	return 0;
}
int find(int x)
{
    int lo = 0, hi = n-1, mid;
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(arr[mid]>=x)
        hi = mid;
        else
        lo = mid+1;
    }
    return arr[hi]==x ? hi : -1;
}
