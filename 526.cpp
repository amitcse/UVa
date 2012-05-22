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
char s1[100],s2[100], path[101][101];
int dp[101][101],l1,l2,i,j;
int pos=1,count=1;
void traceback(char [], char []);
int main()
{

    bool first = true;
	while(gets(s1))
	{
	    gets(s2);
	    if(!first)
			printf("\n");
		else
			first = false;
	    l1 = strlen(s1);
	    l2 = strlen(s2);
	    for(i=0;i<=l1;i++)
	    {
	        dp[i][0] = i;
	        path[i][0] = 'D';
	    }
	    for(i=0;i<=l2;i++)
	    {
	        dp[0][i] = i;
	        path[0][i] = 'I';
	    }
	    dp[0][0] = 0;
	    path[0][0] = ' ';

	    for(i=1;i<=l1;i++)
	    {
	        for(j=1;j<=l2;j++)
	        {
	            int val = (s1[i-1]==s2[j-1]) ? 0 : 1;
	            dp[i][j] = min(min(dp[i-1][j]+1,dp[i][j-1]+1),dp[i-1][j-1]+val);

                if(dp[i-1][j-1]+val<min(dp[i-1][j]+1,dp[i][j-1]+1))
                {
                    if(val==0)
                    path[i][j] = 'C';
                    else
                    path[i][j] = 'S';
                }
                else
                {
                    if(dp[i][j-1]<dp[i-1][j])
                        path[i][j] = 'I';
                    else
                        path[i][j] = 'D';
                }
	        }
	    }
	    cout<<dp[l1][l2]<<endl;
	    traceback(s1,s2);
	}
	return 0;
}

void traceback(char s1[], char s2[])
{
    char seq[100+100+2];
    int len,i,j,k;
    i = strlen(s1);
    j = strlen(s2);
    k = 0;
    while(true)
    {
        if(path[i][j]==' ')
        break;
        else if(path[i][j]=='C')
        {
            seq[k++]='C';i--;j--;
        }
        else if(path[i][j]=='S')
        {
            seq[k++]='S';i--;j--;
        }
        else if(path[i][j]=='I')
        {
            seq[k++]='I';j--;
        }
        else if(path[i][j]=='D')
        {
            seq[k++]='D';i--;
        }
    }

    len = k;
    i=0;j=0;
    int u = 1, v = 1;
    for(k=len-1;k>=0;k--)
    {
        if(seq[k]=='C')
        {
            ++i;++j;++v;
        }
        else if(seq[k]=='S')
        {
            printf("%d Replace %d,%c\n",u,v,s2[j]);
            ++u;v++;i++;j++;
        }
        else if(seq[k]=='I')
        {
            printf("%d Insert %d,%c\n",u,v,s2[j]);
            ++u;++v;++j;
        }
        else if(seq[k]=='D')
        {
            printf("%d Delete %d\n",u,v);
            ++u;++i;
        }
    }
}

/*void disp_op(int i, int j)
{
    int count = 1;
    if(i==0 && j==0)
    return;
    if(path[i][j]==' ')
    disp_op(i-1,j-1);
    else if(path[i][j]=='C')
    {
        disp_op(i-1,j-1);
        printf("%d Replace %d,%c\n",count,pos,s2[j-1]);
    }
    else if(path[i][j]=='D')
    {
        disp_op(i-1,j);
        printf("%d Delete %d\n",count,pos);
    }
    else if(path[i][j]=='I')
    {
        disp_op(i,j-1);
        printf("%d Insert %d,%c\n",count,pos,s2[j-1]);
    }
    if(path[i][j]!='D')
    pos++;
    count++;
}
*/
