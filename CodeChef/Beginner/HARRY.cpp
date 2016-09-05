#include <iostream>

using namespace std;

void clear(int inparr[])
{
    for(int i = 0; i < 26; i++)
        inparr[i] = 0;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int na;

        string inp;
        cin>>inp;

        int inparr[26], counterarr[26];

        clear(inparr);

        for(int i = 0; i < inp.length(); i++)
        {
            inparr[inp[i] - 'a']++;
        }

        cin>>na;
        clear(counterarr);

        for(int i = 0; i < na; i++)
        {
            string keys;
            cin>>keys;

            for(int j = 0; j < keys.length(); j++)
            {
                counterarr[keys[j] - 'a']++;
            }
        }

        bool flag = true;

        for(int i = 0; i < 26; i++)
        {
            if(inparr[i] > counterarr[i])
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