#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INF 1<<30
using namespace std;
long long geese[30000];
bool cmp(long long a, long long b)
{
    return a>b;
}
multiset<int> knights;
multiset<int>::iterator it;

int main()
{
	char error[] = "Loowater is doomed!";
	int n,m,i,j,pos;
    long long cost,best,x;
	while(1)
	{
	    knights.clear();
	    scanf("%d %d",&n,&m);
	    if(n==0 && m==0)
	    break;

	    for(i=0;i<n;i++)
	    scanf("%lld",&geese[i]);
	    for(i=0;i<m;i++)
	    {
	        geti(x);
	        knights.insert(x);
	    }
	    if(m<n)
	    {
	        printf("%s\n",error);
	        continue;
	    }

	    bool flag = false;
	    cost = 0;
	    for(i=0;i<n;i++)
	    {
	        it = knights.lower_bound(geese[i]);
	        if(it==knights.end())
	        {
	            flag = true;
	            break;
	        }
	        cost += (*it);
	        knights.erase(it);
	    }
	    if(flag)
	    printf("%s\n",error);
	    else
	    printf("%lld\n",cost);
	}
	return 0;
}
