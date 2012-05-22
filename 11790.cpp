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
int h[30000],l[30000];
int main()
{
	int t,n,i,j,li,ld,cn=0;
	geti(t);
	while(t--)
	{
	    cn++;
	    geti(n);
	    for(i=0;i<n;i++)
	        scanf("%d",&h[i]);
	    for(i=0;i<n;i++)
            scanf("%d",&l[i]);

        int len_i[n],len_d[n],lis[n],lds[n];
        for(i=0;i<n;i++)
        {
            lis[i] = 1;
            lds[i] = 1;
        }
        len_i[0] = l[0];
        len_d[0] = l[0];
        for(i=1;i<n;i++)
        {
            len_i[i] = l[i];
            len_d[i] = l[i];
            for(j=0;j<i;j++)
            {
                if(l[i]>0 && lis[j]+1==lis[i] && len_i[j]+l[i] > len_i[i])
                {
                    len_i[i] = len_i[j]+l[i];
                }
                else if(l[i]>0 && lis[j]+1 > lis[i] && len_i[j]+l[i] > len_i[i] && h[j]<h[i])
                {
                    len_i[i] = len_i[j]+l[i];
                    lis[i] = lis[j]+1;
                }
                if(l[i]>0 && lds[j]+1==lds[i] && len_d[j]+l[i] > len_d[i])
                {
                    len_d[i] = len_d[j]+l[i];
                }
                else if(l[i]>0 && lds[j]+1 >= lds[i] && len_d[j]+l[i] > len_d[i] && h[j]>h[i])
                {
                    len_d[i] = len_d[j]+l[i];
                    lds[i] = lds[j] + 1;
                }
            }
        }
        /*cout<<endl;
        for(i=0;i<n;i++)
        cout<<lis[i]<<" ";
        cout<<endl;
        for(i=0;i<n;i++)
        cout<<len_i[i]<<" ";
        cout<<endl;
        cout<<endl;
        for(i=0;i<n;i++)
        cout<<lds[i]<<" ";
        cout<<endl;
        for(i=0;i<n;i++)
        cout<<len_d[i]<<" ";
        cout<<endl;*/
        li = -1;
        ld = -1;
        for(i=0;i<n;i++)
        {
            if(li<len_i[i])
            li = len_i[i];
            if(ld<len_d[i])
            ld = len_d[i];
        }
        if(li>=ld)
        printf("Case %d. Increasing (%d). Decreasing (%d).\n",cn,li,ld);
        else
        printf("Case %d. Decreasing (%d). Increasing (%d).\n",cn,ld,li);
	}
	return 0;
}
