#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	long long int n,i,c,l,first,of;
	int neg;
	while(1)
	{
	    scanf("%lld",&n);
	    if(n==0)
            break;
        else
        {
            printf("%lld = ",n);
            neg=0;
            first=0;
            of=0;
            c=0;
            if(n==-1)
            {printf("-1\n");continue;}
            if(n<0)
            {printf("-1 x ");n*=-1;neg=1;}
            if(n==1)
            {
             printf("1\n");
             continue;
            }
            i=2;
            //l=sqrt(n);
            for(i=2;i*i<=n;i++)
            {

                c=0;
                if(n%i==0)
                {
                    while(n%i==0)
                    {
                        n/=i;
                        c++;
                    }
                    {
                            while(c--)
                            {
                                if(first++==0)
                                {of++;printf("%lld",i);}
                                else
                                printf(" x %lld",i);
                            }
                    }
                }
            }
            if(n>1 && of==0)
            printf("%lld",n);
            else if(n>1)
            printf(" x %lld",n);
            printf("\n");
        }
	}
	return 0;
}
