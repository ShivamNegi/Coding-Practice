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
    int data[] = {1, 2, 3, 4, 5};
    vi a(data, data + sizeof(data) / sizeof(data[0]));
    int data1[] = {0, 2, 4, 6, 8};
    vi b(data1, data1 + sizeof(data1) / sizeof(data1[0]));
    display_vi(a, " ");
    display_vi(b, " ");

/*
    For these algorithms the input data should always be sorted.
    The complexity is O(N + M)
*/

    vi out(max(a.size(), b.size()));
    cout<<"The set difference is: \n";
    vi res = vi (out.begin(), set_difference(all(a), all(b), out.begin()));    
    display_vi(res, " ");

    cout<<"The set intersection is: \n";
    res = vi (out.begin(), set_intersection(all(a), all(b), out.begin()));    
    display_vi(res, " ");

    out.resize(a.size() + b.size());
    cout<<"The set union is: \n";
    res = vi (out.begin(), set_union(all(a), all(b), out.begin()));    
    display_vi(res, " ");

    cout<<"The set symmetric difference is: \n";
    res = vi (out.begin(), set_symmetric_difference(all(a), all(b), out.begin()));    
    display_vi(res, " ");
    
    return 0;
}

