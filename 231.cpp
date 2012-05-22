#include <iostream>
using namespace std;

int main()
{
    long long arr[100000],LIS[100000];
    long long n,i,j,a,c=1,maxlength;
    while(1)
    {
        maxlength = 1;
        cin>>a;
        if(a==-1)
        break;
        else
        {
            arr[0]=a;
            LIS[0]=1;
            i=1;
            while(1)
            {
                cin>>a;
                if(a==-1)
                break;
                else
                {
                    arr[i]=a;
                    LIS[i]=1;
                    i++;
                }
            }
            n=i;
            //cout<<n<<endl;
            for(i=1;i<n;i++)
            {
                for(j=0;j<i;j++)
                {
                    if(arr[j]>=arr[i] && LIS[j]+1 > LIS[i])
                    LIS[i]=LIS[j]+1;
                }
                if(LIS[i]>maxlength)
                maxlength = LIS[i];
            }
            if(c>1)
            cout<<endl;
            cout<<"Test #"<<c<<":"<<endl;
            c++;
            cout<<"  maximum possible interceptions: "<<maxlength<<endl;
        }
    }
}
