#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)
#define INF (1<<30)
using namespace std;

bool comp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.first == p2.first)
    return p1.second < p2.second;

    return p1.first < p2.first;
}

int main()
{
    //freopen("in.txt","r",stdin);
	int t;
	bool blank = false;
	geti(t);
	while(t--)
	{
	    int m,x,y,l,i;
	    scanf("%d",&m);
	    vector<pair<int, int> > v;
	    vector<pair<int, int> > res;
	    while(scanf("%d %d",&x,&y))
	    {
	        if(x==0 && y==0)
	        break;
	        v.pb(mp(x,y));
	    }
	    sort(v.begin(),v.end(),comp);

	    /*for(i=0;i<v.size();i++)
	    {
	        cout<<v[i].first<<" "<<v[i].second<<endl;
	    }
	    cout<<endl;*/

	    l = v.size();
	    int curr_left = 0;
	    int curr_right = 0;
	    i = 0;
	    int maxright,ans;
	    ans =-1;
	    maxright = -INF;
	    bool flag = false;
	    while(curr_right < m && i<l && !flag)
	    {
	        //cout<<"curr_ rite = "<<curr_right<<endl;
	        //i = ans+1;
	        while(v[i].first <= curr_right && i<l)
	        {
	            //cout<<"  "<<v[i].first<<" "<<v[i].second<<endl;
	            if(maxright<v[i].second)
	            {
	                //cout<<"    selected "<<endl;;
	                maxright = v[i].second;
	                ans = i;
	            }
	            i++;
	        }
	        if(v[ans].second <= curr_right)
	        {
	            flag = true;
	            //cout<<" breaking "<<endl;
	            break;
	        }
	        curr_left = v[ans].first;
	        curr_right = v[ans].second;
	        res.pb(v[ans]);
	        i = ans+1;
	    }
	    if(flag || ans == -1)
	    {
	        if(blank)
	        printf("\n");
	        blank = true;
	        printf("0\n");
	        continue;
	    }
	    ans = res.size();
	    if(blank)
	    printf("\n");
	    blank = true;
	    printf("%d\n",ans);
	    for(i=0;i<ans;i++)
	    cout<<res[i].first<<" "<<res[i].second<<endl;
	}
	return 0;
}
