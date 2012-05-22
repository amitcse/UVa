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
#define INFINITY 1<<30
using namespace std;

int main()
{
	int n,len,temp,i,j,k,x,sum;
	while(scanf("%d",&n)!=EOF)
	{
	    sum = 0;
	    int f[n+1];
	    for(i=1;i<=n;i++)
	    {
	        scanf("%d",&x);
	        sum += x;
	        f[i] = x;
	    }
	    int cost[n+2][n+1];
	    int sum_of_freq[n+2][n+1];
	    for(i=1;i<=n+1;i++)
	    {
	        cost[i][i-1] = 0;
	        sum_of_freq[i][i-1] = 0;
	    }

	    for(len=1;len<=n;len++)
	    {
	        for(i=1;i<=n+1-len;i++)
	        {
	            j = i+len-1;
	            //cout<<"i= "<<i<<"  j= "<<j<<endl;
	            cost[i][j] = INFINITY;
	            sum_of_freq[i][j] = sum_of_freq[i][j-1] + f[j];
                //cout<<"  sum of frq= "<<sum_of_freq[i][j]<<endl;
	            for(k=i;k<=j;k++)
	            {
	                //cout<<"  k= "<<k<<endl;
	                temp = cost[i][k-1] + cost[k+1][j] + sum_of_freq[i][j];
	                //cout<<"  temp= "<<temp<<" cost= "<<cost[i][j]<<endl;
	                if(temp<cost[i][j])
	                {
	                    cost[i][j] =  temp;
	                    //cout<<"updated\n";
	                }
	            }
	        }
	    }
	    cout<<(cost[1][n]-sum)<<endl;
	}
	return 0;
}
