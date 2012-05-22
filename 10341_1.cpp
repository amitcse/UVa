#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
double p,q,r,s,t,u;
double func(double x)
{
    return ( p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u);
}
double func_d(double x)
{
    return ( -p*exp(-x) + q*cos(x) - r*sin(x) + s/(cos(x)*cos(x)) + 2*t*x);
}
int main()
{
    while(scanf("%lf",&p)!=EOF)
    {
        scanf("%lf %lf %lf %lf %lf",&q,&r,&s,&t,&u);
	double x0, x1;
	double limit = 1e-7;
	if(func(0) * func(1) > 0) /////////       newton method
    {
             cout<<"No solution\n";
             continue;
    }
	x0 = 0.5;
	while(1)
	{
	    cout<<x0<<"  "<<func(x0)<<endl;
        if(func(x0)==0)
        break;
	    x1 = x0 - (func(x0)/func_d(x0));
	    if(fabs(x1-x0)<limit)
	    break;
	    x0 = x1;
	}
	printf("%.4lf\n",x0);
    }
    return 0;
}
