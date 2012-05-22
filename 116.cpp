#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <climits>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;

bool mycmp(list<int> l1, list<int> l2)
{
    int len = l1.size(),i;
    list<int>::iterator it1,it2;
    it1 = l1.begin();
    it2 = l2.begin();
    for(;it1!=l1.end();it1++,it2++)
    {
        if(*it1<*it2)
        return true;

        if(*it1==*it2)
        continue;

        return false;
    }
    /*for(i=0;i<len;i++)
    {
        if(v1[i]>v2[i])
        return true;

        if(v1[i]==v2[i])
        continue;

        return false;
    }*/
}
int main()
{
	int m,n,mini,i,j,up;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
	    int arr[50][150], dist[50][150],prev[50][150];
	    for(i=0;i<m;i++)
	    for(j=0;j<n;j++)
	    scanf("%d",&arr[i][j]);

	    for(i=0;i<m;i++)
	    {
	        dist[i][0] = arr[i][0];
	        prev[i][0] = -1;
	    }

	    for(j=1;j<n;j++)
	    {
	        for(i=0;i<m;i++)
	        {
	            if(i==0) up = m-1;
	            else up = i-1;
	            cout<<up<<" "<<i<<" "<<(i+1)%m<<endl;
	            dist[i][j] = min(min(dist[up][j-1],dist[i][j-1]), dist[(i+1)%m][j-1]) + arr[i][j];

	            prev[i][j] = m+1;
	            if(dist[i][j]==(dist[up][j-1]+arr[i][j]) && prev[i][j]>up)
	            prev[i][j] = up;
	            if(dist[i][j]==(dist[i][j-1]+arr[i][j]) && prev[i][j]>i)
	            prev[i][j] = i;
	            if(dist[i][j]==(dist[(i+1)%m][j-1]+arr[i][j]) && prev[i][j]>((i+1)%m))
	            prev[i][j] = (i+1)%m;

	        }
	    }
	    for(i=0;i<m;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<prev[i][j]<<" ";
	        cout<<endl;
	    }
	    mini = INT_MAX;
	    for(i=0;i<m;i++)
	    {
	        if(dist[i][n-1]<mini)
	        mini = dist[i][n-1];
	    }

	    int k = 0;
	    list<int> v[m];
	    list<int>::iterator it;
	    for(i=0;i<m;i++)
	    {
	        if(dist[i][n-1]==mini)
	        v[k++].pb(i);
	    }
	    for(j=n-1;j>0;j--)
	    {
	        for(i=0;i<k;i++)
	        {
	            v[i].push_front(prev[v[i].front()][j]);
	        }
	    }
	    /*for(i=0;i<k;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<v[i][j]<<" ";
	        cout<<endl;
	    }*/
	    sort(v,v+k,mycmp);
	    for(it=v[0].begin();it!=v[0].end();it++)
	    cout<<*it+1<<" ";
	    cout<<endl;
	    cout<<mini<<endl;
	    /*for(i=0;i<k;i++)
	    {
	        for(j=0;j<n;j++)
	        cout<<v[i][j]<<" ";
	        cout<<endl;
	    }*/
	}
	return 0;
}
