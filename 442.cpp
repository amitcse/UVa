#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;

int main()
{
	int n,i,a,b,p,flag,sum;
	geti(n);
	vector<pair<int,int> > v(26);
	char mat;
	for(i=0;i<n;i++)
	{
	    cin>>mat>>a>>b;
	    v[mat-'A'] = make_pair(a,b);
	}
	string str;
	int r1,r2,c1,c2,x,len;
	while(cin>>str)
	{
	    len = str.length();
	    if(len==1)
	    {
	        cout<<"0\n";
	        continue;
	    }
	    stack<pair<int,int> > s;
	    i=0;
	    flag = 0;
	    sum = 0;
	    while(i<len)
	    {
	        if(str[i]=='(')
	        {
	            i++;
	            continue;
	        }
	        else if(str[i]>='A' && str[i]<='Z')
	            {
	                s.push(v[str[i]-'A']);
	                //cout<<"pushed "<<str[i]-'A'<<endl;
	            }
            else
            {
                r2 = s.top().first;
                c2 = s.top().second;
                s.pop();
                r1 = s.top().first;
                c1 = s.top().second;
                s.pop();
                if(c1!=r2)
                {
                    cout<<"error\n";
                    flag = 1;
                    break;
                }
                else
                {
                    x = r1*c1*c2;
                    sum += x;
                    s.push(make_pair(r1,c2));
                    //cout<<"pushed m "<<r1<<" "<<c2<<endl;
                }
            }
            i++;
	    }
	    if(!flag)
	    cout<<sum<<endl;
	}
	return 0;
}
