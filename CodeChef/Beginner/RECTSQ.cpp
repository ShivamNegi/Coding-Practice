#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else 
        return gcd(b, a % b);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a, b;
        cin>>a>>b;
        int g = gcd(a, b);
        int area1 = a * b, area2 = g * g;
        cout<<area1 / area2<<endl;
    }
    return 0;
}