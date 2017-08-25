#include <bits/stdc++.h>

using namespace std;

bool isprime(int no)
{
    if(no == 1)
        return false;
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
        int m, n;
        cin>>m>>n;

        for(int i = m; i <= n; i++)
        {
            if(isprime(i))
                cout<<i<<"\n";
        }

        cout<<"\n";
    }

    return 0;
}