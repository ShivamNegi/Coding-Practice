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

        int first_half[26], second_half[26];

        for(int i = 0; i < 26; i++)
        {
            first_half[i] = 0;
            second_half[i] = 0;
        }

        
        if(inp.length() % 2 == 0)
        {
            for(int i = 0; i < half; i++)
            {
                first_half[inp[i] - 'a']++;
            }

            for(int i = half; i < inp.length(); i++)
            {
                second_half[inp[i] - 'a']++;
            }
        }
        else
        {
            for(int i = 0; i < half; i++)
            {
                first_half[inp[i] - 'a']++;
            }

            for(int i = half + 1; i < inp.length(); i++)
            {
                second_half[inp[i] - 'a']++;
            }
        }

        bool flag = true;

        for(int i = 0; i < 26; i++)
        {
            if(first_half[i] != second_half[i])
            {
                flag = false;
                break;
            }
        }

        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}