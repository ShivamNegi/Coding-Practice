#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int revno, copyno;
        copyno = n;
        revno = 0;

        while(n != 0)
        {
            revno = revno * 10 + n % 10;
            n /= 10;
        }

        if(copyno == revno)
        {
            cout<<"wins\n";
        }
        else
        {
            cout<<"losses\n";
        }
    }
    return 0;
}