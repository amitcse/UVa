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
int m[15][15];
int s[15][15];
void print(int, int);

int main()
{
	int n,cn = 0;
	while(1)
	{
	    cn++;
	    geti(n);
	    if(n==0)
	    break;
	    int i,r,c,j,k,l,temp;
	    int v[n][2];
	    for(i=0;i<n;i++)
	    {
	        scanf("%d %d",&v[i][0],&v[i][1]);
	        //v.pb(make_pair(r,c));
	    }

	    for(i=0;i<n;i++)
        m[i][i] = 0;

	    for(l=2;l<=n;l++)
	    {
	        for(i=0;i<=n-l;i++)
	        {
	            j = i+l-1;
	            m[i][j] = INFINITY;
	            for(k=i;k<j;k++)
	            {
	                temp = m[i][k] + m[k+1][j] + (v[i][0]*v[k][1]*v[j][1]);
	                if(temp<m[i][j])
	                {
	                    m[i][j] = temp;
	                    s[i][j] = k;
	                }
	            }
	        }
	    }
	    /*for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<m[i][j]<<" ";
	        cout<<endl;
	    }
	    cout<<endl;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<s[i][j]<<" ";
	        cout<<endl;
	    }*/
	    printf("Case %d: ",cn);
	    print(0,n-1);
	    printf("\n");
	}
	return 0;
}

void print(int i, int j)
{
    if(i==j)
    printf("A%d",i+1);
    else
    {
        printf("(");
        print(i,s[i][j]);
        printf(" x ");
        print(s[i][j]+1,j);
        printf(")");
    }
}
