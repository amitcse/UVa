#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void printPath(long);
long long arr[50000],LIS[50000],prev[50000];

int main()
{
    long long n,i,j,maxlength,maxend,flag,c=0;
    int cases;
    char str[20];

    cin.getline(str,20);
    cases = atoi(str);
    //cout<<cases<<endl;
    cin.getline(str,20);
    while(cases--)
    {
        //int maxhit=0;
        i=0;
        maxlength = 1;
        maxend = 0;
        flag=0;
        cin.getline(str,20);
        while(strcmp(str,""))
        {       arr[i] = atoi(str);
                LIS[i]=1;
                prev[i++]=-1;
                cin.getline(str,20);
        }
        n=i;
        //cout<<n;
        /*for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<endl;*/
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(arr[j]<arr[i] && LIS[j]+1 > LIS[i])
                {
                    LIS[i] = LIS[j]+1;
                    prev[i] = j;
                }
            }
            if(LIS[i]>maxlength)
            {
                maxlength = LIS[i];
                maxend = i;
            }
            //maxhit = maxlength;
        }
        if(c++>0)
        cout<<endl;
        cout<<"Max hits: "<<maxlength<<endl;
        printPath(maxend);
        cout<<endl;

        }
       // cout<<"\nexiting";
    return 0;
}
void printPath(long index)
{
    if(prev[index]==-1)
    {
        cout<<arr[index];
        return;
    }
    else
    {
        printPath(prev[index]);
        cout<<"\n"<<arr[index];
    }
}
