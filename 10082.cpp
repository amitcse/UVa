#include <iostream>
#include <cstrig>

using namespace std;

int main()
{
    char kb[100] = {''1234567890QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./};
    int i;
    for(i=0;kb[i];i++)
    cout<<kb[i]<<endl;
    cin>>i;
    return 0;
}
