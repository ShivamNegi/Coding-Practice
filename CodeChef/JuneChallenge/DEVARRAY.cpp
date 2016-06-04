#include <iostream>

using namespace std;

int main()
{
    long long int n, q;
    cin>>n>>q;

    long long int a[n];
    long long int min, max;
    for(long long int i = 0; i < n; i++)
        cin>>a[i];

    min = max = a[0];

    for(long long int i = 0; i < n; i++)
    {
        if(min > a[i])
            min = a[i];
        if(max < a[i])
            max = a[i];
    }

    for(long long int i = 0; i < q; i++)
    {
        long long int t;
        cin>>t;

        if(t >= min && t <= max)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }

    return 0;
}