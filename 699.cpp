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
int lt[50];
int rt[50];
void init()
{
    int i;
    for(i=0;i<50;i++)
	{
	    lt[i] = 0;
	    rt[i] = 0;
	}
}
void calc_sum(int);
int main()
{
    int i,cn = 0;
    while(1){
        cn++;
	init();
	calc_sum(0);
	if(rt[0]==0)
	break;
    printf("Case %d:\n",cn);
	for(i=0;lt[i]>0;i++);
	for(i=i-1;i>=0;i--)
	printf("%d ",lt[i]);
	printf("%d",rt[0]);
	for(i=1;rt[i]>0;i++)
	printf(" %d",rt[i]);
	printf("\n\n");
    }
	return 0;
}

void calc_sum(int idx)
{
    int i;
    cin>>i;
    //cout<<i<<" "<<idx<<endl;
    if(i>0)
    {
        if(idx>=0)
        rt[idx] += i;
        else
        lt[-idx-1] += i;

        calc_sum(idx-1);
        calc_sum(idx+1);
    }
}
