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

int main()
{
    string str;
	int t,x,i,j;
	geti(t);
	cin.ignore();
	while(t--)
	{
	    int sum = 0,cap;
	    getline(cin,str);
	    stringstream ss(str);
	    vector<int> v;
	    while(ss>>x)
	    {
	        v.pb(x);
	        sum+=x;
	    }

	    if((sum%2)!=0)
	    {
	        printf("NO\n");
	        continue;
	    }
	    cap = sum/2;
	    int sz = (int)(v.size());
	    int dp[sz+1][cap+1];

	    for(i=0;i<=cap;i++)
	    dp[0][i] = 0;

	    for(i=1;i<=sz;i++)
	    {
	        for(j=0;j<=cap;j++)
	        {
	            if(v[i-1] > j)
	            dp[i][j] = dp[i-1][j];

	            else
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1]]+v[i-1]);
	        }
	    }
	    if(dp[sz][cap]==cap)
	    printf("YES\n");
	    else
	    printf("NO\n");
	}
	return 0;
}
