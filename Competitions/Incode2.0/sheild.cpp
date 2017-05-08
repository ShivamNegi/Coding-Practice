#include <iostream>

using namespace std;

int getgcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return getgcd(b, a % b);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;

        int gcd = getgcd(a, b);

        if(c % gcd == 0)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}