#include <cstdio>
using namespace std;



int main()
{
	unsigned long long arr[40000]={0};
	int coins[5]={1,10,5,25,50};
	int i,j,c,n;
	arr[0]=1;
	for(i=0;i<5;i++)
	{
		c=coins[i];
		for(j=c;j<=30000;j++)
			arr[j]+=arr[j-c];
	}
	while(scanf("%d",&n)!=EOF)
	{
		if(arr[n]==1)
		printf("There is only 1 way to produce %d cents change.\n",n);
		else
		printf("There are %llu ways to produce %d cents change.\n",arr[n],n);
	}
	return 0;
}
