#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define mp make_pair
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
bool comp(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> > p2)
{
    return p1.first > p2.first;
}

int main()
{
    int n,i,j,x,y,z,max,maxlen,sz,cn=0;
    vector<pair<int, pair<int, int> > > v;
    while(scanf("%d",&n) && n)
    {
        cn++;
        v.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&x,&y,&z);
            v.pb(mp(x,mp(y,z)));
            v.pb(mp(x,mp(z,y)));
            v.pb(mp(y,mp(x,z)));
            v.pb(mp(y,mp(z,x)));
            v.pb(mp(z,mp(x,y)));
            v.pb(mp(z,mp(y,x)));
        }
        int sz = n*6;
        int len[sz];
        sort(v.begin(),v.end(),comp);
        /*cout<<endl;
        for(i=0;i<sz;i++)
        {
            cout<<v[i].first<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;
        }*/
        maxlen = -1;
        for(i=0;i<sz;i++)
        {
            len[i] = v[i].second.second;
            max = -1;
            for(j=0;j<i;j++)
            {
                if(v[j].first > v[i].first && v[j].second.first > v[i].second.first && max<len[j])
                {
                    max = len[j];
                }
            }
            if(max>-1)
            {
                len[i] += max;
            }
            if(maxlen<len[i])
            {
                maxlen = len[i];
            }
        }
        printf("Case %d: maximum height = %d\n",cn,maxlen);
    }
	return 0;
}
