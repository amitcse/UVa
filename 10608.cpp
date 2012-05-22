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

int parent[30030];
int rank[30030];
int numnodes[30030];
void unite(int, int);
int find(int);

int main()
{
	int t,i,x,y,max;
	scanf("%d",&t);
	while(t--)
	{
	    int n,m;
	    scanf("%d %d",&n,&m);

	    for(i=1;i<=n;i++)
	    {
	        parent[i] = i;
	        rank[i] = 0;
	        numnodes[i] = 1;
	    }

	    for(i=0;i<m;i++)
	    {
	        scanf("%d %d",&x,&y);
	        unite(x,y);
	    }
	    max = -1;
	    for(i=1;i<=n;i++)
	    {
	        if(numnodes[i]>max)
	        max = numnodes[i];
	    }
	    cout<<max<<endl;
	}
	return 0;
}

int find(int x)
{
    if(parent[x]==x)
    return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);

    if(xroot==yroot)
    return;

    if(rank[xroot] < rank[yroot])
    {
        parent[xroot] = yroot;
        numnodes[yroot] += numnodes[xroot];

    }
    else if(rank[yroot] < rank[xroot])
    {
        parent[yroot] = xroot;
        numnodes[xroot] += numnodes[yroot];
    }

    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
        numnodes[xroot] += numnodes[yroot];
    }
}
