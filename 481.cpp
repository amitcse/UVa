#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int arr[100000];
int main()
{
	int i,k=0,j;
	while(geti(i)!=EOF)
	{
	    arr[k++] = i;
	}
	vector<int> v[k],p[k];
	int max = 0;
	for(i=0;i<k;i++)
	{
	    j=0;
	    while(v[j].size()!=0 && v[j].back()<arr[i])
	    j++;
	    if(j>max)
	    max = j;
	    v[j].pb(arr[i]);
	    if(j>0)
	    p[j].pb(v[j-1].size()-1);
	}
	cout<<max+1<<endl;
    cout<<"-"<<endl;
	/*for(i=0;i<=max;i++)
	{
	    for(j=0;j<v[i].size();j++)
	    cout<<v[i][j]<<" ";
	    cout<<endl;
	}
	cout<<endl;
	for(i=0;i<=max;i++)
	{
	    for(j=0;j<p[i].size();j++)
	    cout<<p[i][j]<<" ";
	    cout<<endl;
	}*/
	int pos = v[max].size()-1;
	k = 0;
	while(max>=0)
	{
	    arr[k++] = v[max][pos];
	    if(max>=1)pos = p[max][pos];
	    max--;
	}
	for(i=k-1;i>=0;i--)
	cout<<arr[i]<<endl;
	return 0;
}

