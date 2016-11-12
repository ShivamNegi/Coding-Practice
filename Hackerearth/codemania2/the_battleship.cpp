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

void get_pmfs(ll y, set<ll> &a)
{
    while(y % 2 == 0)
    {
        a.insert(0, 2);
        y /= 2;
    }
    ll i = 3;
    while(i <= y)
    {
        while(y % i == 0)
        {
            a.insert(0, i);
            y /= i;
        }
        i += 2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--)
    {
        ll y, x1, x2;
        cin>>y>>x1>>x2;

        set<ll> pm_f;
        
        get_pmfs(y, pm_f);

        

    }
    return 0;
}

