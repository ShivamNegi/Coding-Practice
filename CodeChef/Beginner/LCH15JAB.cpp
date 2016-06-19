#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;

        int half = inp.length() / 2;

        if(inp.length() % 2 != 0)
        {
            cout<<"NO\n";
        }
        else
        {
            int alpha[26];

            for(int i = 0; i < 26; i++)
                alpha[i] = 0;

            for(int i = 0; i < inp.length(); i++)
            {
                alpha[int(inp[i] - 'a')]++;
            }

            bool flag = false;
            for(int i = 0; i < 26; i++)
            {
                if(alpha[i] == half)
                {
                    flag = true;
                    break;
                }
            }

            if(flag)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
    return 0;
}