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

int main()
{
    int t;
    cin>>t;

    map<int, int> a;

    for(int i = 0; i < t; i++)
    {
        int no;
        cin>>no;
        if(a.find(no) != a.end())
            a[no]++;
        else
            a[no] = 1;
    }

    ll max_val = 0;
    map<int, int>:: iterator it = a.begin();
    for(it; it != a.end(); it++)
    {
        max_val += it->second / 2;
    }

    cout<<max_val<<endl;

    return 0;
}

