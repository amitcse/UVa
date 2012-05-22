#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#define pb(x) push_back(x)
#define rep(i,x,y) for(i=x;i<y;i++)
#define geti(x) scanf("%d",&x)

using namespace std;
map<string, int> m;
map<string, int>::iterator it1,it2;
vector<int> adj[300];
int inp;
int d[300];
bool vis[300];

bool isadj(string s1, string s2)
{
    int i,count=0;
    if(s1.length()==s2.length())
    {
        for(i=0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])
            count++;
            if(count>1)
            return false;
        }
        return true;
    }
    return false;
}

void refresh()
{
    int i;
    for(i=0;i<inp;i++)
    {
        d[i] = 0;
        vis[i] = false;
    }
}

void init()
{
    for(int i=0;i<=inp;i++)
    adj[i].clear();
    m.clear();
}

void bfs(int node, int destination)
{

    int temp,i,l;
    queue<int> q;
    vis[node] = true;
    d[node] = 0;
    q.push(node);
    while(!q.empty())
    {
        temp = q.front();

        if(temp==destination)
        return;

        q.pop();
        //cout<<temp<<" ";

        l = adj[temp].size();
        for(i=0;i<l;i++)
        {
            if(!vis[adj[temp][i]])
            {
                vis[adj[temp][i]] = true;
                d[adj[temp][i]] = d[temp]+1;
                //cout<<adj[temp][i]<<" ";
                q.push(adj[temp][i]);
            }
        }
    }
}

int main()
{
	int t;
	string str,str1,str2;
	bool f = true;
	geti(t);
	getline(cin,str);
	while(t--)
	{
        int i,j;
	    inp = 1;
	    int start,destination;
	    if(!f)
	    cout<<endl;
	    f = false;
	    while(true)
	    {
	        cin>>str;
	        if(str[0]=='*')
	        break;
	        m[str] = inp++;

	    }
	    //cout<<"hi";
	    for(it1=m.begin();it1!=m.end();it1++)
	    {
	        for(it2=m.begin();it2!=m.end();it2++)
	        {
	            if(it1==it2)
	            continue;
	            if(isadj(it1->first,it2->first))
	            {
	                adj[it1->second].pb(it2->second);
	            }
	        }
	    }

	    /*for(i=1;i<=m.size();i++)
	    {
	        cout<<i<<" ";
	        for(j=0;j<adj[i].size();j++)
	        cout<<adj[i][j]<<" ";
	        cout<<endl;
	    }*/
	    getline(cin,str);
	    while(true)
	    {
	        getline(cin,str);
	        if(str=="")
	        break;
	        stringstream ss(str);
	        ss>>str1>>str2;
	        //cout<<str1<<" "<<str2<<endl;
            start = m[str1];
            destination = m[str2];
            bfs(start,destination);
            cout<<str1<<" "<<str2<<" "<<d[destination]<<endl;
            refresh();

	    }
	    init();
	}
	return 0;
}
