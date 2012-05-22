#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

int search(vector<int> &,int);
int main()
{
    string s1,s2;
    vector<int> a,b,a1;
    int i,x;
    size_t as,bs,a1_s;
    while(getline(cin,s1))
    {
        a.clear();
        b.clear();
        a1.clear();
        getline(cin,s2);
        stringstream in1(s1),in2(s2);
        while(in1>>x)
        a.push_back(x);
        while(in2>>x)
        b.push_back(x);
        /*for(i=0;i<a.size();i++)
        cout<<a[i]<<" ";
        cout<<endl;
        for(i=0;i<b.size();i++)
        cout<<b[i]<<" ";
        cout<<endl;*/
        as = a.size();
        bs = b.size();
        if(as==0 || bs==0)
        cout<<"A and B are disjoint\n";
        else
        {
            for(i=0;i<as;i++)
            {
                if(search(b,a[i]))
                a1.push_back(a[i]);
            }
            a1_s = a1.size();
            //cout<<"contents of a1\n";
            //for(i=0;i<a1_s;i++)
            //cout<<a1[i]<<" ";
            //cout<<endl;
            if(a1_s==0)
            cout<<"A and B are disjoint\n";
            else if(a1_s==as && a1_s<bs)
            cout<<"A is a proper subset of B\n";
            else if(a1_s<as && a1_s==bs)
            cout<<"B is a proper subset of A\n";
            else if(a1_s == as && a1_s == bs)
            cout<<"A equals B\n";
            else
            cout<<"I'm confused!\n";
        }
    }
    return 0;
}
int search(vector<int> &a,int n)
{
    size_t size = a.size();
    int i;
    for(i=0;i<size;i++)
    {
        if(a[i]==n)
        {
            return 1;
        }
    }
    return 0;
}
