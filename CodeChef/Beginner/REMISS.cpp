#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int a, b;
        cin>>a>>b;

        if(a > b)
            cout<<a;
        else
            cout<<b;
        cout<<" "<<a+b<<endl;
    }
    return 0;
}