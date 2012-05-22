#include <iostream>
#include <cmath>
#define hl 300
using namespace std;

int morethanthree(int);
int primes[hl];
int main()
{
    int i,j,m,n,isprime;
    primes[0]=primes[1]=1;
    i=2;j=2;
    m=i*j;
    for(;m<hl;j++)
    {
        primes[m] = 1;
        m = i*j;
    }
    for(i=3;i<hl;i+=2)
    {
        if(!primes[i])
        {
            j = 3;
            m = i*j;
            for(;m<hl;j+=2)
            {
                primes[m] = 1;
                m = i*j;
            }
        }
    }
    while(cin>>n)
    {
        //for(n=1;n<1000;n++){
        isprime=1;
        if(n==0)
        break;
        else
        {
            m=sqrt(n)+1;
            for(i=2;i<m;i++)
            if(!primes[i])
            {
                if(n%i==0)
                {
                    isprime=0;
                    break;
                }
            }
            if(isprime)
            cout<<"prime"<<endl;
            else
            cout<<"Not prime"<<endl;
            if(morethanthree(n)==1)
            cout<<"morethan or equal three prime factors"<<endl;
            if(morethanthree(n)==0)
            cout<<"less than three priime factors"<<endl;
            if(!isprime && morethanthree(n))
            cout<<n<<"Carmichael"<<endl;
            else
            cout<<"Normal"<<endl;
        }
    }
    return 0;
}


int morethanthree(int n)
{
    int i=2,pfactor=0,flag,j,m;
    while(i<=n)
    {

        if((n%i)==0)
        {
            flag=1;
            m=sqrt(i)+1;
            for(j=2;j<m;j++)
            if(!primes[j])
            {
                if(i%j==0)
                {
                    flag=0;
                    break;
                }
            }
            if(flag)
            {
              cout<<i<<" prime factor"<<endl;
              ++pfactor;
            }
            //++pfactor;
        }
        if(pfactor==4)
        return 1;
        i++;
    }
    return 0;
}
