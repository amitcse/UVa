// pending

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
	int n,i,j,k;
	float x;
	while(scanf("%d",&n)!=EOF)
	{
	    float cost[n+1][n+1];
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            if(i==j)
	            cost[i][j] = 0.0;
	            else
	            {
	                scanf("%f",&x);
	                cost[i][j] = -1*log10(x);
	            }
	        }
	    }

        for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        cout<<cost[i][j]<<" ";
	        cout<<endl;
	    }

	    for(k=1;k<=n;k++)
	    {
	        for(i=1;i<=n;i++)
	        {
	            for(j=1;j<=n;j++)
	            cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
	        }
	    }

	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        cout<<cost[i][j]<<" ";
	        cout<<endl;
	    }
	}
	return 0;
}
