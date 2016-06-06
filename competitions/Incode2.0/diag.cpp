#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int no;
        cin>>no;

        int count = (no - 2) / 2;

        if(count % 2 == 0 && count != 0)
            cout<<"2\n";
        else
            cout<<"1\n";
    }

    return 0;
}