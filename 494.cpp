#include <iostream>
using namespace std;

int main()
{
    char str[100000];
    int i,j,c=0;
    while(cin.getline(str,100000))
    {
        c=0;
        for(i=0;str[i];i++)
        {
            if((str[i]>='a'&&str[i]<='z')||(str[i]>='A'&&str[i]<='Z'))
            {
                while((str[i+1]>='a'&&str[i+1]<='z')||(str[i+1]>='A'&&str[i+1]<='Z'))
                     i++;
                      c++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
