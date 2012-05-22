#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
	int n,pos,next_ele,i;
	bool flag;
	while(scanf("%d",&n) && n)
	{
	    while(1){
	    int arr[n];
	    scanf("%d",&arr[0]);
	    if(arr[0] == 0)
	    {
	        printf("\n");
	        break;
	    }
	    for(i=1;i<n;i++)
	    scanf("%d",&arr[i]);

	    stack<int> s;
	    next_ele = 1;
	    pos = 0;
	    flag = false;
	    s.push(next_ele);
	    next_ele++;
	    while(!s.empty())
	    {
	        //cout<<"  "<<arr[pos]<<" top = "<<s.top()<<" next = "<<next_ele<<endl;
	        if(arr[pos]!=s.top() && next_ele > n)
	        {
	            //cout<<" brak "<<endl;
	            flag = true;
	            break;
	        }
	        if(arr[pos]==s.top())
	        {
	            pos++;
	            s.pop();
	            //cout<<"  poppd"<<endl;
	            if(s.empty() && next_ele <= n )
	            {
	                s.push(next_ele);
	                next_ele++;
	            }
	        }
	        else
	        {
	            //cout<<"pushed "<<next_ele<<endl;
	            s.push(next_ele);
	            next_ele++;
	        }
	    }
	    if(!flag)
	    printf("Yes\n");
	    else
	    printf("No\n");}
	}
	return 0;
}
