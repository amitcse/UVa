#include <iostream>
#include <stack>
using namespace std;
int main()
{
    //stack<char> s;
    int c,i,n,empty;
    char arr[200];
    cin>>n;
    cin.getline(arr,200);
    while(n--)
    {

        c=0;
        empty=1;
        stack<char> s;
        cin.getline(arr,200);
        for(i=0;arr[i];i++)
        {
            empty=0;
            if(arr[i]=='(' || arr[i]=='[')
               s.push(arr[i]);
            else
            {
                if(arr[i]==')')
                {
                    if(!s.empty() && s.top()=='(')
                       {
                           s.pop();
                           c=1;
                       }
                       else
                       {c=0;break;}
                }
                else if(arr[i]==']')
                {
                    if(!s.empty() && s.top()=='[')
                    {
                        s.pop();
                        c=1;
                    }
                    else
                    {c=0;break;}
                }
            }
            //if(!s.empty())
            //cout<<"top--"<<s.top()<<endl;
        }
        if(!s.empty())
        c=0;
        if(empty)
        cout<<"Yes"<<endl;
        else{
        if(c)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;}
    }
    return 0;
}
