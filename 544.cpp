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

map<string,int> cities;

int main()
{
	int n,r,i,j,k,p,q,start,end,cnt,cn = 0;
	while(scanf("%d %d",&n,&r) && n && r)
	{
	    cn++;
	    cnt = 1;
	    cities.clear();
	    string x,y;
	    int w;
	    int wtlmt[n+1][n+1];

	    for(i=0;i<=n;i++)
	    for(j=0;j<=n;j++)
	    wtlmt[i][j] = i==j ? 0 : INF;

	    for(i=0;i<r;i++)
	    {
	        cin>>x>>y>>w;
	        if(cities.find(x)==cities.end())
	        {
	            cities[x] = cnt;
	            p = cnt++;
	        }
	        else
	        p = cities[x];

	        if(cities.find(y)==cities.end())
	        {
	            cities[y] = cnt;
	            q = cnt++;
	        }
	        else
	        q = cities[y];

	        wtlmt[p][q] = w;
	        wtlmt[q][p] = w;
	    }
        /*cout<<endl;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        cout<<wtlmt[i][j]<<" ";
	        cout<<endl;
	    }
        cout<<endl;*/

	    cin>>x>>y;
	    start = cities[x];
	    end = cities[y];

	    for(k=1;k<=n;k++)
	    for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
            wtlmt[i][j] = max(wtlmt[i][j], min(wtlmt[i][k], wtlmt[k][j]));

        /*for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=n;j++)
	        cout<<wtlmt[i][j]<<" ";
	        cout<<endl;
	    }*/

        printf("Scenario #%d\n",cn);
        printf("%d tons\n\n",wtlmt[start][end]);
	}
	return 0;
}
