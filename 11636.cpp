#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n,np,count=1;
    while(1)
    {
        np = 0;
        scanf("%d",&n);
        if(n<0)
        break;
        else
        {
            np = log2(n);
            if(pow(2,np)<n)np++;
            printf("Case %d: %d\n",count++,np);
        }
    }
    return 0;
}
