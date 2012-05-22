#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int nbits[32],lbits[32],ubits[32];
unsigned int toNum(int arr[], int l)
{
    unsigned int sum = 0;
    int i;
    for(i=l-1;i>=0;i--)
    {
        sum = sum<<1;
        sum += arr[i];
    }
    return sum;
}

int main()
{
    unsigned int n,l,u,x,p,nl,ll,ul,sum;
    int flag,i;
    memset(nbits,0,sizeof(nbits));
    memset(lbits,0,sizeof(lbits));
    memset(ubits,0,sizeof(ubits));

    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d %d",&l,&u);
        // n to bits
        p = 0;
        x = n;
        while(x!=0)
        {
            nbits[p++] = x&1;
            x = x>>1;
        }
        nl = p;
        for(i=0;i<p;i++)
        cout<<nbits[i]<<" ";
        cout<<endl;

        // L to bits
        p = 0;
        x = l;
        while(x!=0)
        {
            lbits[p++] = x&1;
            x = x>>1;
        }
        ll = p;
        cout<<"lbits = ";
        for(i=0;i<p;i++)
        cout<<lbits[i]<<" ";
        cout<<endl;

        // U to bits
        p = 0;
        x = u;
        while(x!=0)
        {
            ubits[p++] = x&1;
            x = x>>1;
        }
        ul = p;
        cout<<"ubits = ";
        for(i=0;i<p;i++)
        cout<<ubits[i]<<" ";
        cout<<endl;

        for(i=0;i<ll;i++)
        {
            if(nbits[i]==0)
            {
                lbits[i] = 1;
                temp = toNum(lbits,ll);
                if(temp>u)
                {
                    dont = true;
                    lbits[i] = 0;
                    break;
                }
        }
        cout<<"lbits = ";
        for(i=0;i<ll;i++)
        cout<<lbits[i]<<" ";
        cout<<endl;
        if(dont)
        {
            cout<<toNum(lbits,ll)<<endl;
            continue;
        }

        flag = 0;
        if(ll<ul)
        {
            cout<<" ll les than ul\n";
            for(i=ll;i<ul;i++)
            if(nbits[i]==0)
            {
                ubits[i] = 1;
                flag = 1;
                temp = toNum(ubits,ul);
                if(temp>u)
                {
                    dont = true;
                    ubits[i] = 0;
                    break;
                }
            }
        }
        cout<<"ubits = ";
        for(i=0;i<ll;i++)
        cout<<ubits[i]<<" ";
        cout<<endl;

        sum = 0;
        if(flag)
        {
            cout<<"calculating for extra in ul\n";
            for(i=ul-1;i>ll-1;i--)
            {
                sum = sum<<1;
                sum += ubits[i];
            }
        }
        cout<<ll<<endl;
        for(i=ll-1;i>=0;i--)
        {
            cout<<i<<endl;
            cout<<"sum = "<<sum<<endl;
            sum = sum<<1;
            sum += lbits[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
