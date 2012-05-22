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
#define INF 1<<30
#define EPS (1e-9)
using namespace std;

bool AreSame(double a, double b)
{
    return fabs(a - b) < EPS;
}

int main()
{
    int x,y;
	while(scanf("%d %d",&x,&y))
	{
	    if(x==1 && y==1)
	    break;
	    double dest = (double)x/y;
	    double lo, hi, mid;
	    int lnum = 0;
	    int ldenum = 1;
	    int rnum = 1;
	    int rdenum = 0;
	    int mnum = 1;
	    int mdenum = 1;
	    mid = 1.0;
	    while(1)
	    {
	        //cout<<"dest = "<<dest<<" mid = "<<mid<<"  "<<(mid-dest)<<endl;
	        if(AreSame(dest,mid))
	        break;

            if(mid > dest)
            {
                printf("L");
                rnum = mnum;
                rdenum = mdenum;
            }
            else
            {
                printf("R");
                lnum = mnum;
                ldenum = mdenum;
            }
            mnum = lnum+rnum;
            mdenum = ldenum+rdenum;

            mid = (double)mnum/mdenum;
        }
        cout<<endl;
	}
	return 0;
}
