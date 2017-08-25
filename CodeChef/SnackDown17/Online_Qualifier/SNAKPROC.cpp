#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

/*
    Code Here!
*/

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int len;
        string inp;

        cin>>len;
        cin>>inp;

        int val = 0;
        bool flag = true;
        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i] == 'H')
                val++;
            else if(inp[i] == 'T')
                val--;
            if(val > 1 || val < 0)
            {
                flag = false;
                break;
            }
        }
        if(val != 0)
            flag = false;

        if(flag)
            cout<<"Valid\n";
        else
            cout<<"Invalid\n";
    }

    return 0;
}

