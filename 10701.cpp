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
int n;
string pre,in;
void print_post(int,int);
int main()
{
	int t;
	geti(t);
	while(t--)
	{
	    geti(n);
	    cin>>pre>>in;
	    int len = pre.length();
	    print_post(0,len-1);
	    printf("\n");
	}
	return 0;
}
void print_post(int st, int end)
{
    if(end<0 or st>end)
    return;
    if(st==end)
    {
        cout<<in[st];
        return;
    }
    int i;
    int min_pos=1000,min_ele,pos;
    for(i=st;i<=end;i++)
    {
        pos = pre.find(in[i]);
        if(pos<min_pos)
        {
            min_pos = pos;
            min_ele = i;
        }
    }
    print_post(st,min_ele-1);
    print_post(min_ele+1,end);
    cout<<in[min_ele];
}
