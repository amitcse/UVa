#include <iostream>
using namespace std;
int main()
{
    int cases,land,animal,param,farmers;
    cin>>cases;
    while(cases--)
    {
        int sum=0;
        cin>>farmers;
        while(farmers--)
        {
            cin>>land>>animal>>param;
            sum+=land*param;
        }
        cout<<sum<<endl;
    }
    return 0;
}
