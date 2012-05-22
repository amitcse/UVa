#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
double p,q,r,s,t,u;
float error = 1e-7;
double func(double x)
{
    return ((p*exp(-x)) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
int main()
{
	while(cin>>p){
	    cin>>q>>r>>s>>t>>u;
    double high,low,x,val;
    low = 0;
    high = 1;
    if(func(0) * func(1) > 0) /////////       Bisection method
    {
             cout<<"No solution\n";
             continue;
    }
    bool flag=false;
    while((high-low) > error)
    {
        //cout<<low<<"  "<<high<<endl;
           x = (low+high)/2;
           val=func(x);
           //cout<<"  "<<x<<" "<<val<<endl;
           if(val>0) low = x;
           else high = x;

    }
     printf("%.4lf\n",x);
	}
    return 0;
}
