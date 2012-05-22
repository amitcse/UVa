using namespace std;
#include <iostream>
#include <cstring>
#include <cstdlib>
int main()
{
    int cases,n,i;
    char str[20];
    int arr[50000];
    cin>>cases;
    while(cases--)
    {
        str[0]='\0';
        cin.getline(str,20);
        if(str[0]=='\0')
        {
            cases++;
            continue;
        }
        else
        {
            arr[0]=atoi(str);
            while(1)
            {
                cin.getline(str,20);
                if(strlen(str)==0)
                break;
                else
                {
                    arr[i++]=atoi(str);
                }
            }
            n=i;
            cout<<n<<endl;

        }
    }
    return 0;
}
