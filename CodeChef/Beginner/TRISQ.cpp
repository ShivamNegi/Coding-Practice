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
        int nno = no / 2;

        if(no < 4)
            cout<<0<<endl;
        else
        {
            int ans = nno * nno / 2 - nno / 2;
            cout<<ans<<endl;
        }
    }
    return 0;
}