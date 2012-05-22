#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include<sstream>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int inp[1111111];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int t,i,j;
	char nl[10];
	string ord;
    string str;
    bool blank = false;
    cin>>t;
    gets(nl);
    //getchar();

	while(t--)
	{
	    if(blank)
	    {
	        printf("\n");
	    }
	    blank = true;
	    gets(nl);
	    getline(cin,ord);

	    int i=0;

	    stringstream s(ord);
	    while(s>>inp[i++]);

	    vector<string> v(i);
	    for(j=0;j<i-1;j++)
	    {
	        cin>>str;
	        v[inp[j]] = str;
	    }

	    for(j=1;j<i;j++)
	    cout<<v[j]<<"\n";
        gets(nl);
	}
	return 0;
}
