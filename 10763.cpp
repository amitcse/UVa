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
int from[500500],to[500500];
int main()
{
    int n,i,j;
	while(scanf("%d",&n))
	{
	    if(n==0)
	    break;
	    for(i=0;i<n;i++)
	    {
	        scanf("%d %d",&from[i],&to[i]);
	    }
	    sort(from,from+n);
	    sort(to,to+n);
	    //cout<<"sorted\n";
	    bool flag = false;

	    for(i=0;i<n;i++)
	    {
	        if(from[i]!=to[i])
	        {
	            printf("NO\n");
                flag = true;
                break;
	        }
	    }
	    if(!flag)
	    printf("YES\n");
	}
	return 0;
}
