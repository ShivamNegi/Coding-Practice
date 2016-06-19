#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, out = 1;
        cin>>n;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no>>no;            
        }

        for(int i = 2; i <= n; i++)
        {
            out ^= i;
        }

        cout<<out<<endl;
    }
    return 0;
}