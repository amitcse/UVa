#include <cstdio>
using namespace std;



int main()
{
	int arr[7500]={0};
	int coins[5]={1,10,5,25,50};
	int i,j,c,n;
	arr[0]=1;
	for(i=0;i<5;i++)
	{
		c=coins[i];
		for(j=c;j<=7489;j++)	
			arr[j]+=arr[j-c];
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",arr[n]);
	}
	return 0;
}
