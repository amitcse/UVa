#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,i,j,count,temp,size,k;
    cin>>n;
    while(n--)
    {
        count = 0;
        cin>>size;
        int arr[size+10];
        for(i=0;i<size;i++)
        {
            cin>>arr[i];
        }
        for(i=0;i<size-1;i++)
        for(j=0;j<(size-1-i);j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
        cout<<"Optimal train swapping takes "<<count<<" swaps."<<endl;
    }
}
