#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string inp;
        cin>>inp;

        cout<<count(inp.begin(), inp.end(), '1')<<endl;
    }
    return 0;
}