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

int main()
{
	char str1[100][30];
	char str2[100][30];
	char ch;
	int pos=0;
	for()
	pos = 0;
	while(1)
	{
	    ch = cin.get();
	    if(ch=='#')
	    break;
	    else if(ch=='\n')
	    {
	        str2[pos++] = ' ';
	        continue;
	    }
	    else
	    str2[pos++] = ch;
	}

	cout<<str1<<endl;
	return 0;
}
