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
int arr[50050],n;
int tallest_but_shorter(int);
int shortest_but_taller(int);
int main()
{
	int p1,p2,x,q,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	scanf("%d",&q);
	while(q--)
	{
	    scanf("%d",&x);
	    p1 = tallest_but_shorter(x);
	    p2 = shortest_but_taller(x);
	    if(p1==-1)
	    printf("X ");
	    else
	    printf("%d ",arr[p1]);
	    if(p2==-1)
	    printf("X\n");
	    else
	    printf("%d\n",arr[p2]);

	}
	return 0;
}

int tallest_but_shorter(int x)
{
    int lo = 0, hi = n-1, mid;
    while(lo<hi)
    {
        mid = lo + (hi-lo+1)/2;
        if(arr[mid]<x)
        lo = mid;
        else
        hi = mid-1;
    }
    return arr[lo]<x?lo:-1;
}

int shortest_but_taller(int x)
{
    int lo = 0, hi = n-1, mid;
    while(lo<hi)
    {
        mid = lo + (hi-lo)/2;
        if(arr[mid]>x)
        hi = mid;
        else
        lo = mid + 1;
    }
    return arr[hi]>x?hi:-1;
}
