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
int arr[100100];
using namespace std;

int main()
{
	int n,i,j;
	while(1)
	{
	    cin>>n;
	    if(n==0)
	    break;

	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    long long work = 0;
	    i=0;
	    while(i<n)
	    {
	        if(arr[i]==0)
	        {
	            //cout<<" value is zero, i incremented to "<<i+1<<endl;
	            i++;
	            continue;
	        }
	        if(arr[i]>0)  // if buy
	        {
	            //cout<<" value is gt 0 "<<"i = "<<i<<"  "<<arr[i]<<endl;
	            for(j=i+1;j<n;j++)
	            {
	                //cout<<"   j = "<<j<<" value "<<arr[j]<<endl;
	                if(arr[j]<0)
	                {
	                    if(abs(arr[j])>=arr[i])
	                    {
	                        work += arr[i]*(j-i);
	                        arr[j] += arr[i];
	                        arr[i] = 0;
	                        break;
	                    }
	                    else
	                    {
	                        work += abs(arr[j])*(j-i);
	                        arr[i] += arr[j];
	                        arr[j] = 0;
                            break;
	                    }
	                }
	            }
	        }
	        else // if sell
	        {
	            //cout<<" value is lt 0 "<<"i = "<<i<<"  "<<arr[i]<<endl;
	            for(j=i+1;j<n;j++)
	            {
                    //cout<<"   j = "<<j<<" value "<<arr[j]<<endl;
	                if(arr[j]>0)
	                {
	                    if(arr[j] >= abs(arr[i]))
	                    {
	                        work += abs(arr[i])*(j-i);
	                        arr[j] += arr[i];
	                        arr[i] = 0;
	                        break;
	                    }
	                    else
	                    {
	                        work += arr[j]*(j-i);
	                        arr[i] += arr[j];
	                        arr[j] = 0;
	                        break;
	                    }
	                }
	            }
	        }
	    }
	    cout<<work<<endl;
	}
	return 0;
}
