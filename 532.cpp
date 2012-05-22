#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
int z[6] = {0,0,0,0,1,-1};
int x[6] = {0,0,-1,1,0,0};
int y[6] = {-1,1,0,0,0,0};
int a,b,c;
struct node
	{
	    int x,y,z;
	    int steps;
	    char val;
	    node(int a, int b, int c)
	    {
	        z = a; x = b; y = c;
	    }
	};
char arr[50][50][50];
char str[50];
bool visited[50][50][50];
int bfs(int,int,int);
int main()
{

	int i,j,k;
	while(true)
	{
	    for(i=0;i<50;i++)
	    for(j=0;j<50;j++)
	    for(k=0;k<50;k++)
	    visited[i][j][k] = false;
	    int ans = 0;
	    scanf("%d %d %d",&a,&b,&c);
	    if(!a && !b && !c)
	    break;

	    for(k=0;k<a;k++)
	    for(i=0;i<b;i++)
	    {
	        scanf("%s",&str);
	        for(j=0;j<c;j++)
	        arr[k][i][j] = str[j];
	    }

	    /*for(k=0;k<a;k++){
	    for(i=0;i<b;i++)
	    {
	        //scanf("%s",&str);
	        for(j=0;j<c;j++)
	        cout<<arr[k][i][j]<<" ";
	        cout<<endl;
	    }
	    cout<<endl;}*/

	    for(k=0;k<a;k++)
	    for(i=0;i<b;i++)
	    for(j=0;j<c;j++)
	    {
	        if(arr[k][i][j]=='S')
	        {
	            ans = bfs(k,i,j);
	            if(ans==-1)
	            printf("Trapped!\n");
	            else
	            printf("Escaped in %d minute(s).\n",ans+1);
	        }
	    }
	}
	return 0;
}

int bfs(int k, int i, int j)
{
    int r1,p1,q1,p;
    visited[k][i][j] = true;
    node temp(k,i,j);
    temp.steps = 0;

    queue<node> q;
    q.push(temp);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();

        for(p=0;p<6;p++)
        {
            r1 = temp.z+z[p];
            p1 = temp.x+x[p];
            q1 = temp.y+y[p];

            if(r1>=0 && r1<a && p1>=0 && p1<b && q1>=0 && q1<c)
            {
                if(arr[r1][p1][q1]=='E')
                    return temp.steps;

                node t(r1,p1,q1);
                if(!visited[r1][p1][q1] && arr[r1][p1][q1]=='.')
                {
                    visited[r1][p1][q1] = true;
                    t.steps = temp.steps+1;
                    q.push(t);
                }
            }
        }
    }
    return -1;
}
