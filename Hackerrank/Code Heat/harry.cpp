#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp, test;
        cin>>inp;
        cin>>test;
        sort(inp.begin(), inp.end());
        sort(test.begin(), test.end());
        if(inp == test)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }   
    return 0;
}