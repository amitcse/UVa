using namespace std;
#include <iostream>


int n;
int main()
{
    int i,j,a;
    int org_order[50],dp[50][50];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        org_order[a-1]=i+1;
    }

    int stu_order[50];
    while(cin>>a)
    {
        stu_order[a-1]=1;
        for(i=1;i<n;i++)
        {
            cin>>a;
            stu_order[a-1]=i+1;
        }
        /*for(i=0;i<n;i++)
        {
            cout<<org_order[i]<<" "<<stu_order[i]<<endl;
        }*/
        for(i=0;i<=n;i++)
        {
            dp[i][0]=0;
            dp[0][i]=0;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(org_order[i-1]==stu_order[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
                else if(dp[i-1][j]>=dp[i][j-1])
                dp[i][j] = dp[i-1][j];
                else
                dp[i][j] = dp[i][j-1];
            }
        }
        /*for(i=0;i<=n;i++)
        {
            cout<<endl;
            for(j=0;j<=n;j++)
            cout<<dp[i][j]<<" ";
        }*/
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
