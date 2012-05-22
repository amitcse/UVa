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

using namespace std;
int n;
vector<int> v;
struct config
{
    int lspace;
    int rspace;
    int carno;
    bool operator<(const config &rhs) const;
};
bool config::operator<(const config &rhs) const
{
    if(this->carno == rhs.carno)
    {
        if(this->lspace==rhs.lspace)
        {
            return this->rspace < rhs.rspace;
        }
        else
        return this->lspace < rhs.lspace;
    }
    else
    return this->carno < rhs.carno;
}

map<config, pair<int,char> > dp;
int calc(int, int, int);
void display(int);

int main()
{
		int t,res;
        geti(t);
        while(t--)
        {
            dp.clear();
            v.clear();
            int i,j,k,x;
            scanf("%d",&n);
            n = n*100;

            while(1)
            {
                scanf("%d",&x);
                if(x==0)
                break;
                v.pb(x);
            }
            res = calc(n,n,0);
            cout<<res<<endl;
            display(res);
            if(t>0)
            cout<<endl;
        }
        return 0;
}

int calc(int ls, int rs, int idx)
{
    int ret;
    char path = 'x';
    config c;
    c.lspace = ls;
    c.rspace = rs;
    c.carno = idx;

    if(dp.find(c)!=dp.end())
    {
        return (dp.find(c))->second.first;
    }

    if(idx>=v.size())
    {
        ret = idx;
    }
    else
    {
        int maxl = idx;
        int maxr = idx;
        int curr = v[idx];

        if(curr<=ls)
        {
            maxl = calc(ls-curr, rs, idx+1);
        }
        if(curr<=rs)
        {
            maxr = calc(ls, rs-curr, idx+1);
        }

        if(maxl>maxr)
        {
            ret = maxl;
            path = 'L';
        }
        else
        {
            ret = maxr;
            path = 'R';
        }
    }
    dp.insert(mp(c,mp(ret,path)));

    if(c.lspace!=c.rspace)
    {
        int temp = c.lspace;
        c.lspace = c.rspace;
        c.rspace = temp;
        if(path=='L')
        path = 'R';
        else
        path = 'L';
        dp.insert(mp(c,mp(ret,path)));
    }

    return ret;
}
void display(int num)
{
    config m;
    m.carno = 0;
    m.lspace = n;
    m.rspace = n;

    for(int i=0;i<num;i++)
    {
        m.carno = i;
        map<config,pair<int,char> >::iterator it = dp.find(m);

        if(it->second.second=='L')
        {
            printf("port\n");
            m.lspace -= v[i];
        }
        else if(it->second.second=='R')
        {
            printf("starboard\n");
            m.rspace -= v[i];
        }
    }
}
