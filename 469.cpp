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
int arr[150][150];
int vis[150][150];
void dfs(int,int,int,int,int &);
bool isnum(char ch)
{
    return (ch>='0' && ch<='9');
}
int main()
{
	int t,first=0;
	geti(t);
	char str[150];
	cin.getline(str,150);
	cin.getline(str,150);
	while(t--)
	{
	    int i,j,n,p=0,len,ans,r,c;
        if(first)
        cout<<endl;
        first = 1;
	    while(1)
	    {
	        cin.getline(str,150);
	        //cout<<str<<endl;
	        if(strcmp(str,"")==0)
	        break;
	        else
	        {
	            if(str[0]=='W' || str[0]=='L')
	            {
	                len = strlen(str);
	                for(i=0;i<len;i++)
	                {
	                    arr[p][i] = str[i]=='W'?1:0;
	                }
	                p++;
	            }
	            else
	            {
	                i = r = c = 0;
	                while(i<len && isnum(str[i]))
	                {
	                    r = r*10 + str[i]-'0';
	                    i++;
	                }
	                while(!isnum(str[i]))i++;
	                while(isnum(str[i]) && i<len)
	                {
	                    c = c*10 + str[i]-'0';
	                    i++;
	                }
	                //cout<<r<<" "<<c<<endl;
	                ans = 0;
	                dfs(r-1,c-1,p,len,ans);
	                cout<<ans<<endl;
                    for(i=0;i<p;i++)
                    for(j=0;j<len;j++)
                    vis[i][j] = 0;
	            }

	        }
	    }
	    //cout<<endl;
	}
	return 0;
}

void dfs(int i, int j, int n, int m, int &count)
{
    if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || arr[i][j]==0)
    return;
    else
    {
        vis[i][j] = 1;
        count++;
        dfs(i+1,j,n,m,count);
        dfs(i-1,j,n,m,count);
        dfs(i,j+1,n,m,count);
        dfs(i,j-1,n,m,count);
        dfs(i+1,j+1,n,m,count);
        dfs(i-1,j-1,n,m,count);
        dfs(i+1,j-1,n,m,count);
        dfs(i-1,j+1,n,m,count);
        return;
    }
}
