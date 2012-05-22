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
int d;
long long calc(long long, int, int);
int main()
{
	int t,i;
	long long ans;
	geti(t);
	while(t--)
	{
	    scanf("%d %d",&d,&i);
	    ans = calc(1,i,1);
	    printf("%lld\n",ans);
	}
	return 0;
}
long long calc(long long node, int i, int depth)
{
    if(depth==d)
    return node;

    if((i%2)==0)
    calc((node*2)+1, i/2, depth+1);
    else
    calc(node*2, (i/2)+1, depth+1);
}
