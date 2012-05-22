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

int main()
{
	long long N,L,U,M,mask;
	while(scanf("%lld %lld %lld",&N,&L,&U)!=EOF)
	{
	    M = 0;
	    for(int sift = 31; sift>=0; sift--)
	    {
	        mask = 1LL<<sift;
	        if(mask+M<=U and !(N&mask))
	        {
	            M = M+mask;
	        }
	        else if(mask+M <=L)
	        {
	            M = M+mask;
	        }
	    }
	    printf("%lld\n",M);
	}
    return 0;
}
