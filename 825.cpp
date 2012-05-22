#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
	int t;
	geti(t);
	bool blank = false;
	while(t--)
	{
	    int w,n,x,i,j,nnodes;
	    scanf("%d %d",&w,&n);
	    nnodes = w*n;
	    vector<int> v[nnodes+1];
	    bool unsaf[nnodes+1];
	    int indeg[nnodes+1];
	    for(i=1;i<=nnodes;i++)
	    {
	        unsaf[i] = false;
	        indeg[i] = 0;
	    }
        string str;
        getline(cin,str);
	    for(i=0;i<w;i++)
	    {

	        getline(cin,str);
	        //cout<<str<<endl;
	        stringstream ss(str);
	        ss>>x;
	        //cout<<x<<endl;
	        while(ss>>x)
	        {
	            //cout<<(i*n+x)<<endl;
                unsaf[i*n + x] = true;
	        }
	    }
        //cout<<"test";
	    for(i=0;i<n*(w-1);i+=n)
	    {
	        //cout<<" i = "<<i<<endl;
	        for(j=1;j<n;j++)
	        {
	            if(!unsaf[i+j] && !unsaf[i+j+1])
	            {
	                v[i+j].pb(i+j+1);
	                indeg[i+j+1]++;
	            }
	            if(!unsaf[i+j] && !unsaf[i+j+n])
	            {
	                v[i+j].pb(i+j+n);
	                indeg[i+j+n]++;
	            }
	        }
	        if(!unsaf[i+j] && !unsaf[i+j+n])
            {
                v[i+j].pb(i+j+n);
                indeg[i+j+n]++;
            }
	    }
	    for(j=1;j<n;j++)
	    {
	        if(!unsaf[i+j] && !unsaf[i+j+1])
	        {
	            v[i+j].pb(i+j+1);
	            indeg[i+j+1]++;
	        }
	    }

        /*for(i=0;i<=nnodes;i++)
	    {
	        cout<<i<<"  ";
	        for(j=0;j<v[i].size();j++)
	        {
	            cout<<v[i][j]<<" ";
	        }
	        cout<<endl;
	    }*/

	    queue<int> q;
	    /*for(i=1;i<=nnodes;i++)
	    {
	        if(indeg[i]==0 && !unsaf[i])
	        q.push(i);
	    }*/
	    q.push(1);
	    int p = 1;
	    int top_sorted[nnodes+1];
	    while(!q.empty())
	    {
	        x = q.front();
	        //cout<<"  extracted "<<x<<endl;
	        q.pop();
	        top_sorted[p++] = x;
	        for(i=0;i<v[x].size();i++)
	        {
	            indeg[v[x][i]]--;
	            if(indeg[v[x][i]]==0)
	            q.push(v[x][i]);
	        }
	    }


	    /*for(i=1;i<p;i++)
	    cout<<top_sorted[i]<<" ";
	    cout<<endl;*/
        //cout<<p<<endl;
        if(top_sorted[p-1]!=nnodes)
        {
            if(blank)
            printf("\n");
            blank = true;
            printf("0\n");
            continue;
        }
	    int numpath[nnodes+1];
	    for(i=1;i<=nnodes;i++)
	    numpath[i] = 0;
	    numpath[top_sorted[p-1]] = 1;
	    //numpath[top_sorted[p-2]] = 1;

	    for(i=p-2;i>=1;i--)
	    {
	        int node = top_sorted[i];
	        //cout<<"  node = "<<node<<endl;
	        for(j=0;j<v[node].size();j++)
	        {
	            //cout<<"   n node = "<<v[node][j]<<endl;
	            numpath[node] += numpath[v[node][j]];
	        }
	        //cout<<"    here = "<<numpath[node]<<endl;
	    }
	    /*for(i=1;i<nnodes;i++)
	    cout<<numpath[i]<<" ";
	    cout<<endl;*/
	    if (blank)
	    printf("\n");
	    blank = true;
	    printf("%d\n",numpath[1]);
	}
	return 0;
}

/*
1
8 8
1
2
3 5
4 1 4
5 3 6
6 2 7
7 8
8
*/
