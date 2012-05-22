#include <iostream>
using namespace std;

long long check(long long);

int main()
{
	long long arr[2000];
	arr[0]=1;
	long long i=1,count=1,c;
	while(count<=1500)
	{
		c=check(i);
		if(c)
		{
			arr[count++]=i;
			//cout<<arr[count-1]<<" ";
		}
		i++;
	}
	cout<<arr[1500];
	return 0;
}
long long check(long long n1)
{
	while(n1>1)
	{
		if((n1%2)==0)
		n1/=2;
		else{
		if((n1%3)==0)
		n1/=3;
		else{
		if((n1%5)==0)
		n1/=5;
		else return 0;}}
	}
	return 1;
}
