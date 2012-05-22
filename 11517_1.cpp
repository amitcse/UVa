#include <cstdio>
using namespace std;

int main()
{

    int cases,i,n,j,ncoins,coin;
    int ans[100000] = {0};
    scanf("%d",&cases);
    while(cases--)
    {
        for(i=0;i<=10000;i++)
            ans[i]=0;
        scanf("%d",&n);
        scanf("%d",&ncoins);
        for(i=0;i<ncoins;i++)
        {
            scanf("%d",&coin);
            for(j=10000;j>coin;j--)
            {
                if(ans[j-coin])
                {
                    if(ans[j]==0 || ans[j]>ans[j-coin]+1)
                    {
                        ans[j]=ans[j-coin]+1;
                    }
                }
            }
            ans[coin]=1;
        }
        for(i=n;;i++)
        {
            if(ans[i])
            {
                printf("%d %d\n",i,ans[i]);
                break;
            }
        }
    }
}
