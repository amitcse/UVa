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
char s[100100],t[100100];
long lens,lent;
bool isSubsequence(long long, long long);
int main()
{
	while(scanf("%s",s)!=EOF)
	{
	    scanf("%s",t);
	    lens = strlen(s);
	    lent = strlen(t);
	    if(lens>lent)
	    {
	        printf("No\n");
	        continue;
	    }
	    if(isSubsequence(0,0))
	    printf("Yes\n");
	    else
	    printf("No\n");
	}
	return 0;
}
bool isSubsequence(long long idxs, long long idxt)
{
    if(idxs>=lens)
    return true;

    if(idxt>=lent)
    return false;

    long long i;
    for(i=idxt;i<lent;i++)
    {
        if(s[idxs]==t[i])
        {
            if(isSubsequence(idxs+1,i+1))
            return true;
        }
    }
    return false;
}
