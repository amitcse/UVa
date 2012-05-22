#include <cstring>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cases,count=0;
    cin>>cases;
    while(cases--)
    {
        count++;
        if(count!=1) printf("\n");
        string line;
        int arr[101][101], len;
        int i,j,r,c,temp,max;
        cin>>line;
        len = line.length();

        for(i=0;i<len;i++) arr[0][i] = line[i]-'0';
        for(i=1;i<len;i++)
        {
            cin>>line;
            for(j=0;j<len;j++) arr[i][j] = line[j]-'0';
        }
        for(i=1;i<len;i++)
            for(j=0;j<len;j++)
                arr[i][j] += arr[i-1][j];

        max = 0;
        for(i=0;i<len;i++)
         {
              for(j=0;j<len;j++)
              {
                   for(r=1;r<=(len-i);r++)
                   {
                        temp=0;
                        for(c=1;c<=(len-j);c++)
                        {
                             temp+=arr[i+r-1][j+c-1];
                             if(i>0) temp-=arr[i-1][j+c-1];

                             if(temp==(r*c) && max<(r*c)) max=r*c;
                             if(temp<(r*c)) break;
                        }
                   }
              }
         }
        printf("%d\n",max);
    }
    return 0;
}

