#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char seq1[200],seq2[200];
    int i,j,c=1;
    while(1)
    {
        cin.getline(seq1,200);
        if(seq1[0]=='#')
        break;
        else
        {
            cin.getline(seq2,200);
            int dp[500][500];
            int n1,n2;
            n1=strlen(seq1);
            n2=strlen(seq2);
            //cout<<n1<<"  "<<n2<<endl;
            //for(i=0;i<n1;i++)
            //cin>>tower1[i];
            //for(i=0;i<n2;i++)
            //cin>>tower2[i];
            for(i=0;i<=n1;i++)
            dp[i][0]=0;
            for(i=0;i<=n2;i++)
            dp[0][i];
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
            /*for(i=1;i<=n1;i++)
            {
                for(j=1;j<=n2;j++)
                {
                    cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }*/
            cout<<"Case #"<<c<<": you can visit at most "<<dp[n1][n2]<<" cities."<<endl;
            //cout<<"Number of Tiles : "<<dp[n1][n2]<<"\n"<<endl;
            c++;
            }
        }
}
