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

char str[50];
int arr[50][50];
int visited[50][50];
void dfs(int, int, int);
int main()
{
	int n,cases=1;
	while(geti(n)!=EOF)
	{
	    int i,j,count=0;

	    for (i=0;i<n;i++)
	    {
	        scanf("%s",str);
	        for(j=0;j<n;j++)
	        arr[i][j] = str[j]-'0';
	    }

	    for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    visited[i][j] = 0;

	    /*for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<arr[i][j]<<" ";
	        cout<<endl;
	    }*/
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(!visited[i][j])
	            {
	                if(arr[i][j]==0)
	                {
	                    visited[i][j]=1;
	                    continue;
	                }
	                count++;
	                //cout<<count<<endl;
	                dfs(i,j,n);
	            }
	        }
	    }
	    printf("Image number %d contains %d war eagles.\n",cases++,count);
	}
	return 0;
}
void dfs(int i,int j,int n)
{
    if(i<0 || i>=n || j<0 || j>=n || visited[i][j] || arr[i][j]==0)
    return ;
    else
    {
        visited[i][j] = 1;
        dfs(i+1,j,n);
        dfs(i-1,j,n);
        dfs(i,j+1,n);
        dfs(i,j-1,n);
        dfs(i-1,j-1,n);
        dfs(i+1,j+1,n);
        dfs(i-1,j+1,n);
        dfs(i+1,j-1,n);
    }
}
