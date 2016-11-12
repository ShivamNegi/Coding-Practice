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
        int l, o;
        cin>>l>>o;

        int max_val = (l + (l - 1)) / o;
        int counter = 0;
        max_val = max_val * o;
        //cout<<max_val<<endl;

        while(max_val)
        {
            if(max_val > l + 1)
            {
                int diff = (max_val - 1) - l;
                counter += max_val - 1;
                counter -= diff * 2;
            }
            else
            {
                counter += max_val - 1;
            }
            //cout<<counter<<endl;
            max_val -= o;
        }

        cout<<counter<<endl;
    }
    return 0;
}

