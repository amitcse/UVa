#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <climits>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int m,n,mini,i,j,up;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
	    int arr[50][150], dist[50][150],prev[50][150],start;
	    for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	    scanf("%d",&arr[i][j]);

	    for(i=0;i<m;i++)
	    {
	        dist[i][n-1] = arr[i][n-1];
	        //prev[i][0] = -1;
	    }

	    for(j=n-2;j>=0;j--)
	    {
	        for(i=0;i<m;i++)
	        {
	            if(i==0) up = m-1;
	            else up = i-1;
	            //cout<<up<<" "<<i<<" "<<(i+1)%m<<endl;
	            dist[i][j] = min(min(dist[up][j+1],dist[i][j+1]), dist[(i+1)%m][j+1]) + arr[i][j];

	            prev[i][j] = m+1;
	            if(dist[i][j]==(dist[up][j+1]+arr[i][j]) && prev[i][j]>up)
	            prev[i][j] = up;
	            if(dist[i][j]==(dist[i][j+1]+arr[i][j]) && prev[i][j]>i)
	            prev[i][j] = i;
	            if(dist[i][j]==(dist[(i+1)%m][j+1]+arr[i][j]) && prev[i][j]>((i+1)%m))
	            prev[i][j] = (i+1)%m;

	        }
	    }
        /*for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<dist[i][j]<<" ";
	        cout<<endl;
	    }

	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n-1;j++)
	        cout<<prev[i][j]<<" ";
	        cout<<endl;
	    }*/
	    mini = INT_MAX;
	    for(i=0;i<m;i++)
	    {
	        if(dist[i][0]<mini)
	        {
	            mini = dist[i][0];
	            start = i;
	        }
	    }

	    vector<int>v;
	    v.pb(start);
	    for(i=0;i<n-1;i++)
	    {
	        v.pb(prev[start][i]);
	        start = v.back();
	    }
	    bool space = false;
	    for(i=0;i<n;i++)
	    {
	        if(space)
	        printf(" ");
	        space = true;
	        cout<<v[i]+1;
	    }
	    cout<<endl;
	    cout<<mini<<endl;
	}
	return 0;
}
