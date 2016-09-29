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
        int n;
        cin>>n;

        string inp;
        cin>>inp;

        ll tot_sum = 0;
        ll curr_sum = 1;
        for(int i = 0; i < n; i++)
        {
            if(inp[i + 1] - inp[i] == 1 || inp[i] - inp[i + 1] == 25)
                curr_sum++;
            else
                {tot_sum += curr_sum* (curr_sum + 1) / 2;
                    curr_sum = 1;
                }


        }

        cout<<tot_sum<<endl;
    }
    return 0;
}

