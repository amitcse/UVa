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

int main()
{
    string str;
	vector<string> v;
	while(1)
	{
	    cin>>str;
	    if(str[0]=='#')
	    break;
	    v.pb(str);
	}
	/*for(int i=0;i<v.size();i++)
	cout<<v[i]<<endl;*/
	int i,j,k,l1,l2,l,len,flag,sz,p,x;
	char frm,to;
	vector<int> adj[30];
	bool vis[30];
	int indeg[30];
	char sorted[30];
	for(i=0;i<30;i++)
	{
	    vis[i] = false;
	    indeg[i] = 0;
	}
	len  = v.size();
	for(i=0;i<len-1;i++)
	{
	    l1 = v[i].length();
	    for(j=i+1;j<len;j++)
	    {
	        flag = 0;
	        l2 = v[j].length();
	        l = (l1<l2)?l1:l2;
	        for(k=0;k<l;k++)
	        {
	            frm = v[i][k];
	            to = v[j][k];
	            flag = 0;
	            if(frm==to)
	            continue;
	            if(frm!=to)
	            {
	                //cout<<i<<" "<<j<<" "<<frm<<" "<<to<<endl;
	                sz = adj[frm-'A'].size();
	                for(p=0;p<sz;p++)
	                {
	                    if(adj[frm-'A'][p]==to-'A')
	                    {
	                        flag = 1;
	                        break;
	                    }
	                }
	                if(!flag)
	                {
	                    adj[(frm-'A')].pb((to-'A'));
	                    vis[frm-'A'] = true;
	                    vis[to-'A'] = true;
	                    indeg[to-'A']++;
	                }
                    break;
	            }
	        }
	    }
	}
	/*for(i=0;i<26;i++)
	{
	    cout<<char('A'+i)<<"  ";
	    for(j=0;j<adj[i].size();j++)
	    cout<<char('A'+adj[i][j])<<" ";
	    cout<<endl;
	}
	for(i=0;i<26;i++)
	cout<<indeg[i]<<" ";
	cout<<endl;*/
	queue<int> q;
    for(i=0;i<26;i++)
    if(indeg[i]==0 && vis[i])
    q.push(i);
    p = 0;
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        sorted[p++] = 'A'+x;
        len = adj[x].size();
        for(i=0;i<len;i++)
        {
            indeg[adj[x][i]]--;
            if(indeg[adj[x][i]]==0)
            q.push(adj[x][i]);
        }
    }
    for(i=0;i<p;i++)
    printf("%c",sorted[i]);
    printf("\n");
	return 0;
}
