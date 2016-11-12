#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector< vi > vvi;
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

void factors(int c, vector< pair<int, int> >& k)
{
    for(int i = 1; i <= sqrt(c); i++)
    {
        if(c % i == 0)
        {
            k.push_back(make_pair(i, c / i));
        }
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m, c;
        cin>>n>>m>>c;

        vector< pair<int, int> > k;
        factors(c, k);

        int counter = 0;
        for(int i = 0; i < k.size(); i++)
        {
            if(k[i].first <= n && k[i].second <= m)
                counter++;
            if(k[i].first <= m && k[i].second <= n && !(k[i].first == k[i].second))
                counter++;
        }

        cout<<counter<<endl;
    }
    return 0;
}

