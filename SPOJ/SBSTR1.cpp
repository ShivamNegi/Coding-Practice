#include <bits/stdc++.h>

using namespace std;


// Lol! this problem is not allowed for C++.
int main()
{
    int t = 24;

    while(t--)
    {
        string a, b;
        cin>>a>>b;

        // check if b is a substring of a.
        if(a.find(b) != string::npos)
            cout<<"1\n";
        else
            cout<<"0\n";
    }

    return 0;
}