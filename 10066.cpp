#include <iostream>
using namespace std;

int main()
{
    int n1,n2,i,j,c=1;
    while(1)
    {
        cin>>n1>>n2;
        if(n1==0 && n2==0)
        break;
        else
        {
            int tower1[500],tower2[500],dp[500][500];
            for(i=0;i<n1;i++)
            cin>>tower1[i];
            for(i=0;i<n2;i++)
            cin>>tower2[i];
            for(i=0;i<=n1;i++)
            dp[i][0]=0;
            for(i=0;i<=n2;i++)
            dp[0][i];
            for(i=1;i<=n1;i++)
            for(j=1;j<=n2;j++)
            {
                if(tower1[i-1]==tower2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j]=dp[i-1][j];
                else
                dp[i][j]=dp[i][j-1];
            }
            cout<<"Twin Towers #"<<c<<endl;
            cout<<"Number of Tiles : "<<dp[n1][n2]<<"\n"<<endl;
            c++;
            }
        }
}
