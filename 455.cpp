#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
bool isperiod(string,int,int);
int main()
{
	int t,i;
	bool space = false;
	geti(t);
	while(t--)
	{
	    if(space)
	    cout<<endl;
	    space = true;
	    string str;
	    cin>>str;
	    bool ans = false;
	    int len = str.length();
	    for(i=1;i<=len/2;i++)
	    {
	        if(isperiod(str,i,len))
	        {
	            cout<<i<<endl;
	            ans = true;
	            break;
	        }
	    }
	    if(!ans)
	    cout<<len<<endl;
	}
	return 0;
}

bool isperiod(string str, int i, int len)
{
    if((len%i)!=0)
    return false;
    string pre = str.substr(0,i);
    //cout<<pre<<endl;
    int start = 0;
    int loop = len/i;
    while(loop--)
    {
        string next = str.substr(start,i);
       //cout<<"  "<<next<<endl;
        if(pre!=next)
        {return false;}
        start += i;
    }
    return true;
}
