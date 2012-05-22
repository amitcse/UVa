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
#define INF 21474836

using namespace std;

int main()
{
	int n,i,j,k,num,mul;
	scanf("%d",&n);
	int adj[n][n];
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	adj[i][j] = 0;
	int mincost[n][n];
	cin.ignore();
	string str;

	for(i=1;i<n;i++)
	{
	    k = 0;
	    getline(cin,str);
	    for(j=0;j<str.length();)
	    {
	        //cout<<" j = "<<j<<endl;
	        if(str[j]==' ')
	        {
	            j++;
	            continue;
	        }

	        if(str[j]=='x')
	        {
	            adj[i][k] = INF;
	            adj[k][i] = INF;
	            k++; j++;
	        }

	        else
	        {
	            num = 0;
	            mul = 10;
	            while(isdigit(str[j]) && j<str.length())
	            {
	                num *= mul;
	                num += (str[j]-'0');
	                //cout<<"    "<<num<<endl;
	                j++;
	            }
	            //cout<<" num = "<<num<<endl;
	            adj[i][k] = num;
	            adj[k][i] = num;
	            k++;
	        }
	    }
	}
	if(n==1)
	printf("0\n");
	else{
	for(k=0;k<n;k++)
	{
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
	        }
	    }
	}
    int ans = 0;
    for(i=0;i<n;i++)
    {
        if(adj[0][i]>ans)
        ans = adj[0][i];
    }
	cout<<ans<<endl;
	/*for(i=0;i<n;i++)
	{
	    for(j=0;j<n;j++)
	    cout<<adj[i][j]<<" ";
	    cout<<endl;
	}*/
	}
	return 0;
}
