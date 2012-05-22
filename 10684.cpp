#include <iostream>
using namespace std;

int maxSubArraySum(int a[],int size)
{
    // 12 -4 -10 4 9 = 13
    int max_ending_here=0,max_so_far=0;
    for(int i=0;i<size;i++)
    {
        max_ending_here += a[i];
        if(max_ending_here<0)
        {
            max_ending_here = 0;
        }
        else if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
    }
    return max_so_far;
}
int main()
{
    int n,i,arr[10010],maxsum;
    //int start=0,end=0;
    while(cin>>n){
        if(n==0) break;
        else{
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    maxsum = maxSubArraySum(arr,n);
    if(maxsum<=0)
    cout<<"Losing streak."<<endl;
    else
    cout<<"The maximum winning streak is "<<maxsum<<".\n";
    }}
    return 0;

}

