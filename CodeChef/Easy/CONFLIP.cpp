#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int g;
        cin>>g;
        while(g--)
        {
            int i, n, q;
            cin>>i>>n>>q;
            long long int heads;
            if(i == 1)
                heads = n / 2;
            else
                heads = n / 2 + 1;
            if(q == 1)
                cout<<heads<<endl;
            else
                cout<<n - heads<<endl;
        }   
    }
    return 0;
}