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
	int n,m,a,b,i,k,next,x,l;
	while(1)
	{
	    scanf("%d %d",&n,&m);
	    if (n==0 && m==0)
	    break;
	    int adj[n+1][n+1];
	    int indeg[n+1];
	    int sorted[n];
	    for(i=0;i<=n;i++)
	    {
	        adj[i][0] = 0;
	        indeg[i] = 0;
	    }
	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d",&a,&b);
	        adj[a][++adj[a][0]] = b;
	        indeg[b]++;
	    }
	    queue<int> q;
	    for(i=1;i<=n;i++)
	    if(indeg[i]==0)
	    q.push(i);
	    k = 0;
	    while(!q.empty())
	    {
	        x = q.front();
	        q.pop();
	        sorted[k++] = x;
	        l = adj[x][0];
	        for(i=1;i<=l;i++)
	        {
	            next = adj[x][i];
	            indeg[next]--;
	            if(indeg[next]==0)
	            q.push(next);
	        }
	    }
	    for(i=0;i<n-1;i++)
	    printf("%d ",sorted[i]);
	    printf("%d\n",sorted[n-1]);
	}
	return 0;
}
