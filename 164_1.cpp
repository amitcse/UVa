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

void find_path(int, int);
char s1[50], s2[50];
int dp[50][50],pos=0;
char path[50][50],chr[50][50];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int m,n,i,j,val;
	while(scanf("%s",&s1)!=EOF)
	{
	    if(s1[0]=='#')
	    break;
	    scanf("%s",&s2);
	    pos=1;
	    m = strlen(s1);
	    n = strlen(s2);

	    dp[0][0] = 0;
	    for(i=1;i<=m;i++)
	    {
	        dp[i][0] = i;
	        path[i][0] = 'D';
	        chr[i][0] = s1[i-1];
	    }
	    for(i=1;i<=n;i++)
	    {
	        dp[0][i] = i;
	        path[0][i] = 'I';
	        chr[0][i] = s2[i-1];
	    }
	    path[0][0] = ' ';
	    chr[0][0] = ' ';
	    for(i=1;i<=m;i++)
	    {
	        for(j=1;j<=n;j++)
	        {
	            val = (s1[i-1]==s2[j-1]) ? 0 : 1;
                dp[i][j] = min(min(dp[i][j-1]+1,dp[i-1][j]+1),dp[i-1][j-1]+val);


                    if( dp[i-1][j-1]+val < min(dp[i-1][j]+1, dp[i][j-1]+1) )
                    {
                        if(val==0)
                        path[i][j] = ' ';
                        else
                        path[i][j] = 'C';
                        chr[i][j] = s2[j-1];
                    }
                    else
                    {
                        if(dp[i][j-1]+1 < dp[i-1][j]+1)
                        {
                            path[i][j] = 'I';
                            chr[i][j] = s2[j-1];
                        }
                        else
                        {
                            path[i][j] = 'D';
                            chr[i][j] = s1[i-1];
                        }
                    }
                }
	        }
	        find_path(m,n);
	        printf("E\n");
	    }
	return 0;
}
void find_path(int i,int j)
{
    if(i==0 && j==0)
    return ;
    if(path[i][j]==' ')
    find_path(i-1,j-1);
    else if(path[i][j]=='C')
    {
        find_path(i-1,j-1);
        printf("%c%c%02d",path[i][j],s2[j-1],pos);
    }
    else if(path[i][j]=='D')
    {
        find_path(i-1,j);
        printf("%c%c%02d",path[i][j],s1[i-1],pos);
    }
    else if(path[i][j]=='I')
    {
        find_path(i,j-1);
        printf("%c%c%02d",path[i][j],s2[j-1],pos);
    }
    if(path[i][j]!='D')
    pos++;
}
