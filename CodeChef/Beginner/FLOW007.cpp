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

        int revno = 0;

        while(no != 0)
        {
            revno = revno * 10 + no % 10;
            no /= 10;
        }

        cout<<revno<<endl;
    }

    return 0;
}

