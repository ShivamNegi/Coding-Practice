#include <iostream>

using namespace std;

int dectobin(int no)
{
    if(no == 1)
        return 1;
    else
        return (no % 2 + dectobin(no / 2) * 10);
}

int main()
{
    int no;
    cin>>no;
    cout<<dectobin(no)<<endl;
    return 0;
}