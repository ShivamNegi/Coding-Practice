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
    vi a(3);

    for(int i = 0; i < 5; i++)
    {
        if(!i)
            a.push_back(i);
        else
            a.insert(a.begin(), i);
    }

    display_vi(a, " ");

    int key, val;
    cin>>key>>val;

    a.insert(find(all(a), key) + 1, val);
    display_vi(a, " ");

    cin>>key;

    if(find(all(a), key) != a.end())
        //cout<<"found\n";
        a.erase(find(all(a), key));
    else
        cout<<"not found\n";
    display_vi(a, " ");
    return 0;
}

