#include <iostream>
#include <regex>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;

        if(regex_match(inp, regex("^https?://www\\..*\\.(com|org|net).*$")) )
            cout<<"true\n";
        else
            cout<<"false\n";
    }       

    return 0;
}