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
int arr[10010],n;
int find_just_smaller(int);
int find(int);
int main()
{
	int m,i,j,pos,pos2,x;
	while(scanf("%d",&n)!=EOF)
	{
	    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);
        sort(arr,arr+n);
	    scanf("%d",&m);
	    x = m/2;
	    pos = find_just_smaller(x);
	    //cout<<"  "<<pos<<" "<<arr[pos]<<endl;
	    //bool flag = false;
	    if(arr[pos]*2 == m)
	    {
            if(arr[pos-1]==arr[pos])
            {
                //cout<<"   "<<arr[pos-1]<<endl;
                printf("Peter should buy books whose prices are %d and %d.\n\n",arr[pos],arr[pos]);
                continue;
            }
            else
            pos--;
	    }

	    for(i=pos;i>=0;i--)
	    {
	        pos2 = find(m-arr[i]);
	        if(pos2==-1)
	        continue;
	        printf("Peter should buy books whose prices are %d and %d.\n\n",arr[i],arr[pos2]);
	        break;
	    }
	}
	return 0;
}

int find_just_smaller(int x)
{
    int lo = 0, hi = n-1, mid;
    while(lo<hi)
    {
        mid = lo + (hi-lo+1)/2;
        if(arr[mid]<=x)
        lo = mid;
        else
        hi = mid-1;
    }
    if(arr[lo]<=x)
    return lo;
    else
    return -1;
}

int find(int x)
{
    int lo = 0, hi = n-1, mid;
    while(lo<=hi)
    {
        mid = lo + (hi-lo)/2;
        if(arr[mid]==x)
        return mid;
        else if (arr[mid]<x)
        lo = mid+1;
        else
        hi = mid-1;
    }
    return -1;
}
