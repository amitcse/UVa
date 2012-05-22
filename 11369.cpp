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

int arr[25000];
bool comp(const int &a, const int &b)
{
    return a>b;
}

int main()
{
	int t,i;
	geti(t);
	while(t--)
	{
	    int n;
	    scanf("%d",&n);
	    for(i=0;i<n;i++)
	    scanf("%d",&arr[i]);

	    long long discount = 0;
	    sort(arr,arr+n,comp);
	    for(i=2;i<n;i=i+3)
	    {
	        discount += arr[i];
	    }
	    printf("%lld\n",discount);
	}
	return 0;
}
