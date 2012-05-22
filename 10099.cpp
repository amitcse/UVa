// MaxiMin Floyd Warshall

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
#define INF -21474836

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
	long long n,r,i,j,k,x,y,w,start,end,tourist,ans,cn = 0;
	while(scanf("%lld %lld",&n,&r) && n && r)
	{
	    cn++;
	    long long path[n+1][n+1];
	    for(i=0;i<=n;i++)
	    for(j=0;j<=n;j++)
	    path[i][j] = i==j ? 0 : INF;

	    for(i=0;i<r;i++)
	    {
	        scanf("%lld %lld %lld",&x,&y,&w);
	        path[x][y] = w-1;
	        path[y][x] = w-1;
	    }

       /* cout<<endl;
                for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            cout<<path[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;*/

	    for(k=1;k<=n;k++)
	    for(i=1;i<=n;i++)
	    //if(path[i][k]!=INF)
	    for(j=1;j<=n;j++)
	    //if(path[k][j]!=INF && i!=j)
            path[i][j] = max(path[i][j], min(path[i][k], path[k][j]));

        /*for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            cout<<path[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;*/
        scanf("%lld %lld %lld",&start, &end, &tourist);
        if(start==end)
        {
            printf("Scenario #%lld\n",cn);
            printf("Minimum Number of Trips = 1\n\n");
            continue;
        }
        int tourist_per_trip = path[start][end];
        ans = tourist/tourist_per_trip;
        if(ans*tourist_per_trip < tourist)
        ans++;

        printf("Scenario #%lld\n",cn);
        printf("Minimum Number of Trips = %lld\n\n",ans);
	}
	return 0;
}
