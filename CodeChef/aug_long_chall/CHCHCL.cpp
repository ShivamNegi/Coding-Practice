#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long n, m;
        cin>>n>>m;

        bool flag = false;

        if(n % 2 == 0)
            flag = !flag;
        if(m % 2 == 0)
            flag = !flag;

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}