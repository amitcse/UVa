#include <iostream>
using namespace std;

int min(int,int,int);

long long check(long long);

int main()
{
	long long arr[2000];
	arr[0]=1;
	long long i=1,count=1,c;
	int p1=0,p2=0,p3=0;
	int m2=2,m3=3,m5=5;
	while(i<1500)
	{
		arr[i]=min(m2,m3,m5);
		if(arr[i]==m2)
		{
			//cout<<"p1";
			p1++;
			m2=arr[p1]*2;
		}
		if(arr[i]==m3)
		{
			//cout<<"p2";
			p2++;
			m3=arr[p2]*3;
		}
		if(arr[i]==m5)
		{
			//cout<<"p3";
			p3++;
			m5=arr[p3]*5;
		}
		i++;
		//cout<<arr[i-1]<<" ";
	}
		
	cout<<"The 1500'th ugly number is "<<arr[1499]<<"."<<endl;
	return 0;
}
int min(int a, int b, int c)
{
	if(a<=b)
	{
		if(a<=c)
		return a;
		else
		return c;
	}
	if(b<=c)
	return b;
	else
	return c;
	
}
