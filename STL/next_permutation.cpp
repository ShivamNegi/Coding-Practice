#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_any(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    /*for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;*/
    for(auto i: a)
    {
        cout<<i<<s;
    }
    cout<<endl;
}


int main()
{
    ll no;
    cin>>no;

    vi a;
    while(no)
    {
        a.push_back(no % 10);
        no = no / 10;
    }

    sort(all(a));

    while(next_permutation(all(a)))
    {
        display_vi(a, " ");
    }
    return 0;
}

