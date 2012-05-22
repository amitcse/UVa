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
multimap<int,int> mp;
multimap<int,int>::iterator it;
int main()
{
    int n,i,j,from,to,pos;
	while(scanf("%d",&n) && n)
	{
	    mp.clear();
	    for(i=0;i<n;i++)
	    {
	        scanf("%d %d",&from,&to);
	        it = mp.find(to);
	        if(it==mp.end())
	        {
	            //cout<<"not found -- inserted"<<endl;
	            mp.insert(pair<int,int> (from,to));
	        }
	        else if((*it).second==from)
	        {
	            //cout<<"found -- erased"<<endl;
	            mp.erase(it);
	        }
	        else
	        {
	            //cout<<"found with diff val"<<endl;
	            mp.insert(pair<int,int> (from,to));
	        }
	    //for(it=mp.begin();it!=mp.end();it++)
	    //cout<< (*it).first <<"  "<< (*it).second<<endl;
	    }

	    if(mp.size()==0)
	    printf("YES\n");
	    else
	    printf("NO\n");
	}
	return 0;
}
