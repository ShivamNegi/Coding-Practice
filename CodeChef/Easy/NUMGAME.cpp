#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        unsigned long int no;
        cin>>no;

        if(no % 2 == 0)
            cout<<"ALICE\n";
        else
            cout<<"BOB\n";
    }
    return 0;
}