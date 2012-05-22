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
string str;
bool isperiod(int, int);
int main()
{
	//string str;
	while(1)
	{
	    cin>>str;
	    if(str[0]=='.')
	    break;
	    int len = str.length(),i;
	    int l = len/2;
	    bool ans = false;
	    for(i=1;i<=l;i++)
	    {
	        if(isperiod(i,len))
	        {
	            cout<<len/i<<endl;
	            ans = true;
	            break;
	        }
	    }
	    if(!ans)
	    cout<<"1"<<endl;
	}
	return 0;
}

bool isperiod(int i, int len)
{
    if((len%i)!=0)
    return false;
    string pre = str.substr(0,i);
    int start = 0, loop;
    loop = len/i;
    while(loop--)
    {
        if(pre!=str.substr(start,i))
        return false;
        start += i;
    }
    return true;
}
