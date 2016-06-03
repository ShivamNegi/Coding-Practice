#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        unsigned long long int no;
        cin>>no;
        if(no == 1)
            cout<<"Yes\n";
        else if(floor(sqrt(no)) == sqrt(no))
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
    
    return 0;
}