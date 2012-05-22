using namespace std;
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define LLU long long unsigned int
#define LLD long long double
#include<limits>
#define MAX_INT numeric_limits<int>::max()
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int price,NO,coins[110];
        cin>>price;
        cin>>NO;
        for(int i=0;i<NO;i++)
        cin>>coins[i];
        int dp[10010];
        for(int i=0;i<10010;i++)
            dp[i]=MAX_INT;
        //cout<<MAX_INT<<endl;
        dp[0]=0;
        for(int i=0;i<NO;i++)
        {
            for(int j=10000;j>=0;j--)
            {
                if(dp[j]!=MAX_INT){
                    //cout<<j<<"--j i=="<<i<<" ";
                    if(j+coins[i]<=10000)
                        if(dp[j+coins[i]]>dp[j]+1){
                            //cout<<dp[j+coins[i]]<<"  dp["<<j<<"]+"<<coins[i]<<" > dp["<<j<<"]+1  "<<dp[j]+1<<endl;
                            dp[j+coins[i]]=dp[j]+1;
                        }
                }
            }
            cout<<"endl"<<endl;
        }
        for(int i=price;i<=10009;i++)
        if(dp[i]!=MAX_INT)
        {
            cout<<i<<" "<<dp[i]<<endl;
            break;
        }
    }
    return 0;
}
