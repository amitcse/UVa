#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int ways[501][501];
int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	geti(t);
    bool blank = false;
	while(t--)
	{
	    int w,n,x,i,j,nnodes;
	    scanf("%d %d",&w,&n);

	    for(i=0;i<=500;i++)
	    for(j=0;j<=500;j++)
	    ways[i][j] = -1;

        string str;
        getline(cin,str);
	    for(i=1;i<=w;i++)
	    {
	        getline(cin,str);
	        //cout<<str<<endl;
	        stringstream ss(str);
	        ss>>x;
	        //cout<<x<<endl;
	        while(ss>>x)
	        {
	            //cout<<(i*n+x)<<endl;
                ways[i][x] = 0;
	        }
	    }
	    if(ways[1][1]!=0)
	    ways[1][1] = 1;
	    else
	    {
	        if(blank)
	        printf("\n");
	        blank = true;
	        printf("0\n");
	        continue;
	    }
        for(i=2;i<=n;i++)
	    {
	        if(ways[1][i]!=0)
	        ways[1][i] = ways[1][i-1];
	    }
	    for(i=2;i<=w;i++)
	    {
	        if(ways[i][1]!=0)
	        ways[i][1] = ways[i-1][1];
	    }
	    for(i=2;i<=w;i++)
	    {
	        for(j=2;j<=n;j++)
	        {
	            if(ways[i][j]!=0)
                ways[i][j] = ways[i-1][j] + ways[i][j-1];
	        }
	    }
	    if(blank)
	    printf("\n");
	    blank = true;
	    printf("%d\n",ways[w][n]);
	}
	return 0;
}
