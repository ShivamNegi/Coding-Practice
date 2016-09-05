#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;

        int zeros, ones;
        zeros = ones = 0;

        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i] == '0')
                zeros++;
            else
                ones++;
        }
        
        if(zeros == 1 || ones == 1)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}