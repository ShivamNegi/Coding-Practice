#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp1, inp2;
        cin>>inp1>>inp2;

        bool flag = true;

        for(int i = 0; i < inp1.length(); i++)
        {
            if(inp1[i] != inp2[i])
            {
                if(inp1[i] != '?' && inp2[i] != '?')
                    {
                     flag = false;
                     break;   
                    }
            }
        }

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}
