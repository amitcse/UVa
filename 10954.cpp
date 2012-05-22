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
struct comp
{
    bool operator()(const long long &a, const long long &b)
    {
        return a>b;
    }
};

int main()
{
    int n,i;
    long long sum,x,y,temp;
	while(scanf("%d",&n) && n)
	{
	    priority_queue<long long, vector<long long>, comp> q;
	    for(i=0;i<n;i++)
	    {
	        scanf("%lld",&x);
	        q.push(x);
	    }
	    sum = 0;
	    for(i=1;i<n;i++)
	    {
	        x = q.top();
	        q.pop();
	        y = q.top();
	        q.pop();
	        temp = x+y;
	        sum += temp;
	        q.push(temp);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
