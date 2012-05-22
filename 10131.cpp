#include <iostream>
using namespace std;

void printPath(int);
int weight[1100],iq[1100],LIS[1100],prev[1100],pos[1100];
int main()
{
    int i=0,j,maxlength=1,a,b,n,temp,bestend=0;
    while(cin>>a && cin>>b)
    {
        weight[i]=a;LIS[i]=1;prev[i]=-1;pos[i]=i+1;
        iq[i]=b;
        i++;
    }
    n=i;
    /*cout<<n<<endl;
    k=n;
    for(i=0;i<n;i++){ cout<<weight[i]<<" ";}
    cout<<endl;*/
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(weight[j]>weight[j+1])
            {
                temp = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = temp;
                temp = iq[j];
                iq[j] = iq[j+1];
                iq[j+1] = temp;
                temp = pos[j];
                pos[j] = pos[j+1];
                pos[j+1] = temp;
            }
        }
    }
    /*for(i=0;i<n;i++){ cout<<pos[i]<<" ";}
    cout<<endl;

    for(i=0;i<n;i++){ cout<<weight[i]<<" ";}
    cout<<endl;
    for(i=0;i<n;i++)cout<<iq[i]<<" ";
    cout<<endl;*/
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if( weight[j]<weight[i] && iq[j]>iq[i] && LIS[j]+1 > LIS[i])
            {LIS[i]=LIS[j]+1;
            prev[i]=j;}
        }
        if(LIS[i]>maxlength)
        {maxlength=LIS[i];bestend = i;}
    }
    cout<<maxlength<<endl;
    printPath(bestend);
    return 0;
}
void printPath(int indx)
{
    if (prev[indx]==-1) {
    cout<<pos[indx];
    return;
        }
    printPath(prev[indx]);
    cout<<"\n"<<pos[indx];
}
