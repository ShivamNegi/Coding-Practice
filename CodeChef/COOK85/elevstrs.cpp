#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define rep(a, b) for(int i = a; i < b; i++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef vector< pair<int, int> > vpi;

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
        float dist, vstair, vele;
        cin>>dist>>vstair>>vele;

        vstair = vstair * sqrt(2);

        if(vstair > vele)
            cout<<"Stairs\n";
        else
            cout<<"Elevator\n";
    }
    return 0;
}

