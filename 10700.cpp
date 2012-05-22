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
char str[1000000],str1[1000000];
int main()
{
	int t,i,j,l;
	long long mul,sum,max,min;
	geti(t);
	while(t--)
	{

	    scanf("%s",str);
	    strcpy(str1,str);

	    char *tok;
	    vector<char *>v;
	    tok = strtok(str,"+");
	    while(tok!=NULL)
	    {
	        v.pb(tok);
	        tok = strtok(NULL,"+");
	    }
	    l = v.size();
	    sum = 0;
	    for(i=0;i<l;i++)
	    {
	        mul = 1;
	        tok = strtok(v[i],"*");
	        while(tok!=NULL)
	        {
	            mul *= atoi(tok);
	            //cout<<"i = "<<i<<" "<<tok2<<endl;
	            tok = strtok(NULL,"*");
	        }
	        sum += mul;
	    }
	    min = sum;
	    v.clear();
        tok = strtok(str1,"*");
	    while(tok!=NULL)
	    {
	        v.pb(tok);
	        tok = strtok(NULL,"*");
	    }
	    l = v.size();
	    mul = 1;
        for(i=0;i<l;i++)
	    {
	        sum = 0;
	        tok = strtok(v[i],"+");
	        while(tok!=NULL)
	        {
	            sum += atoi(tok);
	            //cout<<"i = "<<i<<" "<<tok<<endl;
	            tok = strtok(NULL,"+");
	        }
            mul *= sum;
	    }
	    max = mul;
        printf("The maximum and minimum are %lld and %lld.\n",max,min);

	}
	return 0;
}
