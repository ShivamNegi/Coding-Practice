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
        string big, small;

        cin>>big>>small;

        string out = "";

        for (int i = 0; i < small.length(); ++i)
        {
            /* code */
            if(small[i] == 'A')
                out += 'T';
            else if(small[i] == 'T')
                out += 'A';
            else if(small[i] == 'G')
                out += 'C';
            else if(small[i] == 'C')
                out += 'G';
        }

        int k;
        // cout<<big<<endl<<out<<endl;
        if(big.find(out) == -1)
            cout<<"-1\n";
        else
            cout<<big.find(out)<<endl;
    }
    return 0;
}

