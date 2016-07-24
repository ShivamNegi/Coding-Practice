#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long int n, pos, count;
        cin>>n>>pos>>count;

        if(count > (n - pos + 1))
        {
            count = count - ((n - pos) + 1);
            count = count % n;

            if(count == 0)
                cout<<n;
            else
                cout<<count;
            cout<<endl;
        }
        else
        {
            cout<<pos + count - 1<<endl;
        }
    }
    return 0;
}