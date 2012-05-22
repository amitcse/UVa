using namespace std;
#include <iostream>
#include <cmath>
#define size 100000
//(int)(sqrt((8*10000000)+1)/2)+1 = 4473
int main()
{

    unsigned long long arr[size];
    unsigned long long i,n,num,denum,x;
    arr[0]=1;
    //cout<<size<<endl;
    for(i=1;i<size;i++)
    {
        arr[i] = arr[i-1]+i+1;
        //cout<<arr[i]<<" ";
    }
    //cout<<arr[size-1]<<" "<<arr[size-2];
    while(cin>>n){
        i=0;

    while(1)
    {
        if(arr[i]>=n)
        break;
        i++;
    }
    //i++;
    //cout<<i<<" "<<arr[i]<<endl;
        x = arr[i]-n;
        num = 1+x;
        denum = i+1-x;
    cout<<num<<"/"<<denum<<endl;
    }
    return 0;
}
