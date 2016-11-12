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
    int n;
    cin>>n;

    string inp;
    cin>>inp;

    string out1, out2;
    out1 = out2 = "";

    for(int i = 0; i < inp.length(); i++)
    {
        if(i % 2)
        {
            out1 += "#";
            out2 += ".";
        }
        else
        {
            out1 += ".";
            out2 += "#";
        }
    }

    int mis_match1, mis_match0;
    mis_match0 = mis_match1 = 0;

    for(int i = 0; i < inp.length(); i++)
    {
        if(inp[i] != out1[i])
        {
            if(inp[i]  == '#')
                mis_match1++;
            else
                mis_match0++;
        }
    }

    int res = min(mis_match0, mis_match1) + abs(mis_match1 - mis_match0);

    mis_match0 = mis_match1 = 0;

    for(int i = 0; i < inp.length(); i++)
    {
        if(inp[i] != out2[i])
        {
            if(inp[i]  == '#')
                mis_match1++;
            else
                mis_match0++;
        }
    }    

    int r1 = min(mis_match0, mis_match1) + abs(mis_match1 - mis_match0);

    res = res < r1? res: r1;
    if(n == 1 && inp[0] == '.')
        cout<<"1\n";
    else
        cout<<res<<endl;
    return 0;
}