#include <iostream>
using namespace std;

int main()
{
    int cases,i,j,n,flag;
    int seq[1000];
    while(cin>>cases)
    {
        if(cases!=0)
        {
            seq[0]=0;
            j=0;
            flag=0;
            for(i=0;i<cases;i++)
            {
                cin>>n;
                if(n!=0)
                {seq[j++]=n;flag=1;}
            }
            if(flag){
            for(i=0;i<j-1;i++)
            cout<<seq[i]<<" ";
            cout<<seq[j-1]<<endl;
            }
            else
            cout<<"0\n";
        }
        else
        break;
    }
    return 0;
}
