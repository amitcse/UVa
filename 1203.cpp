#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
map<int, int> mp;
struct comp
{
    bool operator()(const pair<int,int> &p1, const pair<int,int> &p2)
    {
        if(p1.second==p2.second)
        return p1.first > p2.first;

        return p1.second > p2.second;
    }
};

int main()
{
	vector<pair<int, int> > v;
	int id,perd,k,i,tid,tprd;
	char cmd[20];
	while(1)
	{
	    scanf("%s",cmd);
	    if(cmd[0]=='#')
	    break;

	    scanf("%d %d",&id,&perd);
	    mp[id] = perd;
	    v.pb(mp(id,perd));
	}
	make_heap(v.begin(),v.end(),comp());
	pair<int, int> p;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
	    p = v.front();
	    pop_heap(v.begin(),v.end(),comp());
	    v.pop_back();
	    tid = p.first;
	    tprd = p.second;
	    printf("%d\n",tid);
	    //cout<<" extracted "<<p.first<<" "<<p.second<<endl;
	    //cout<<"   inserted "<<p.first<<" "<<p.second+mp[p.first]<<endl;
	    v.pb(mp(tid,tprd+mp[tid]));
	    make_heap(v.begin(), v.end(), comp());
	}
	return 0;
}
