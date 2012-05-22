#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    long long int cases,l,h,i,len,j,max,divsum,number;
    scanf("%lld",&cases);
    while(cases--)
    {
        scanf("%lld %lld",&l,&h);
        max = 0;
        for(i=l;i<=h;i++)
        {
            divsum = 0;
            len = sqrt(i);
            //printf("%lld\n",len);
            for(j=1;j<=len;j++)
            {
                if(i%j==0)
                divsum+=2;
            }
            if(len*len==i)
            divsum--;
            //cout<<i<<" "<<divsum<<endl;
            if(max<divsum)
            {
                max = divsum;
                number = i;
            }
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,h,number,max);
    }
    return 0;
}
