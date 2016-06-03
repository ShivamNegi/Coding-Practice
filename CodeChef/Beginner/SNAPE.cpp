#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a, b;
        cin>>a>>b;

        if(a > b)
            cout<<sqrt(a * a - b * b);
        else
            cout<<sqrt(b * b - a * a);
        cout<<" "<<sqrt(a * a + b * b)<<endl;
    }
}
