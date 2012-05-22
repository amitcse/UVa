#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char seq1[1005],seq2[1005];
    int i,j;
    while(cin.getline(seq1,1005))
    {
            if(!strcmp(seq1,""))
            break;
            else{

            cin.getline(seq2,1005);
            int n1,n2;
            n1=strlen(seq1);
            n2=strlen(seq2);
            int dp[n1+1][n2+1];
            for(i=0;i<=n1;i++)
            dp[i][0]=0;
            for(i=0;i<=n2;i++)
            dp[0][i]=0;
            for(i=1;i<=n1;i++)
            for(j=1;j<=n2;j++)
            {
                if(seq1[i-1]==seq2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=dp[i][j-1];
            }
            printf("%d\n",dp[n1][n2]);
            }

        }
}
