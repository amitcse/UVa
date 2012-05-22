#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;

char str[200];
char arr[200][200];
int visited[200][200];
void dfs(int, int, int, int);
int main()
{
	int m,n;
	while(1)
	{
	    geti(m);
	    if(m==0)
	    break;
	    geti(n);
	    int i,j,count=0;

	    for (i=0;i<m;i++)
	    {
	        scanf("%s",str);
	        for(j=0;j<n;j++)
	        arr[i][j] = str[j];
	    }

	    for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    visited[i][j] = 0;

	    /*for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<arr[i][j]<<" ";
	        cout<<endl;
	    }*/
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(!visited[i][j])
	            {
	                if(arr[i][j]=='*')
	                {
	                    visited[i][j]=1;
	                    continue;
	                }
	                count++;
	                dfs(i,j,m,n);
	            }
	        }
	    }
	    printf("%d\n",count);
	}
	return 0;
}
void dfs(int i,int j,int m,int n)
{
    if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || arr[i][j]=='*')
    return ;
    else
    {
        visited[i][j] = 1;
        dfs(i+1,j,m,n);
        dfs(i-1,j,m,n);
        dfs(i,j+1,m,n);
        dfs(i,j-1,m,n);
        dfs(i-1,j-1,m,n);
        dfs(i+1,j+1,m,n);
        dfs(i-1,j+1,m,n);
        dfs(i+1,j-1,m,n);
    }
}
