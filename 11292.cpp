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
#define INF 1<<30
using namespace std;
long long geese[30000],knights[30000];
bool cmp(long long a, long long b)
{
    return a>b;
}

int main()
{
	char error[] = "Loowater is doomed!";
	int n,m,i,j,pos;
    long long cost,best;
	while(1)
	{
	    scanf("%d %d",&n,&m);
	    if(n==0 && m==0)
	    break;

	    for(i=0;i<n;i++)
	    scanf("%lld",&geese[i]);
	    for(i=0;i<m;i++)
	    scanf("%lld",&knights[i]);
	    if(m<n)
	    {
	        printf("%s\n",error);
	        continue;
	    }
	    sort(geese,geese+n,cmp);
	    sort(knights,knights+m,cmp);
	    bool flag = false;
	    cost = 0;
	    for(i=0;i<n;i++)
	    {
	        best = INF;
	        for(j=0;j<m;j++)
	        {
	            if(knights[j]<best && knights[j]!=-1 && knights[j]>=geese[i])
	            {
	                pos = j;
	                best = knights[j];
	            }
	            //if(knights[j]<geese[i] && knights[j]!=-1)
	            //break;
	        }
	        //cout<<best<<"  "<<pos<<"  "<<knights[pos]<<endl;
	        if(best==INF)
	        {
                flag = true;
	            break;
	        }
	        else
	        {
	            cost += best;
	            knights[pos] = -1;
	        }
	    }
	    if(flag)
	    printf("%s\n",error);
	    else
	    printf("%lld\n",cost);
	}
	return 0;
}
