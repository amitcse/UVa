#include <iostream>
using namespace std;

int org_order[50];
int n;
int index(int);
int main()
{
    int i,maxlength,j,a;
    cin>>n;
    for(i=0;i<n;i++)
    {cin>>a;org_order[a-1]=i+1;}
    int stu_order[n],LIS[n];
    LIS[0]=1;
    while(cin>>a)
    {
        stu_order[a-1]=1;
        maxlength = 1;
        for(i=1;i<n;i++)
        {
            cin>>a;
            stu_order[a-1]=i+1;
            LIS[i]=1;
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                //cout<<"index(stu_order["<<j<<"] ="<<index(stu_order[j])<<"  index(stu_order["<<i<<"] ="<<index(stu_order[i])<<endl;
                if((index(stu_order[j]) < index(stu_order[i])) && LIS[j]+1 > LIS[i])
                LIS[i] = LIS[j]+1;
            }
            if(LIS[i]>maxlength)
            maxlength = LIS[i];
        }
        cout<<maxlength<<endl;
    }

}
int index(int a)
{
    int i;
    for(i=0;i<n;i++)
    if(a==org_order[i])
    break;
    return i;
}
