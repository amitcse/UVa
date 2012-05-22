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

int arr[10][10];
int  vis[10][10];
pair<int,int> p1,p2;
char s1[10],s2[10];
int x[8] = {1,-1,1,-1,-2,-2,2,2};
int y[8] = {-2,-2,2,2,-1,1,-1,1};

int bfs();
void init()
{
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
    {
        arr[i][j] = 0;
        vis[i][j] = 0;
    }
}
int main()
{
	while(cin>>s1>>s2)
	{
	    p1.second = s1[0]-'a'+1;
	    p1.first = s1[1]-'0';
	    p2.second = s2[0]-'a'+1;
	    p2.first = s2[1]-'0';
	    init();
	    int ans = bfs();
	    printf("To get from %s to %s takes %d knight moves.\n",s1,s2,ans);

	}
	return 0;
}

int bfs()
{
    queue<pair<int,int> > q;
    q.push(p1);
    vis[p1.first][p1.second] = 1;
    arr[p1.first][p1.second] = 0;
    while(!q.empty())
    {
        p1 = q.front();
        q.pop();
        int a = p1.first;
        int b = p1.second;
        for(int i=0;i<8;i++)
        {
            int k = a+x[i];
            int l = b+y[i];
            if(k>=1 && k<=8 && l>=1 && l<=8 && !vis[k][l])
            {
                vis[k][l] = 1;
                arr[k][l] = arr[a][b]+1;
                q.push(make_pair(k,l));
            }
        }
        if(vis[p2.first][p2.second])
        return arr[p2.first][p2.second];
    }
    return arr[p2.first][p2.second];
}
