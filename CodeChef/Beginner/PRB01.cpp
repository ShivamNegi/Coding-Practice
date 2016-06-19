#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int no)
{
    for(int i = 2; i <= sqrt(no); i++)
    {
        if(no % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int no;
        cin>>no;

        if(isprime(no))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}