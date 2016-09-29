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
    int n;
    cin>>n;

    string inp;
    cin>>inp;

    vector< pair <int, int> > v1;
    vector< pair <int, int> > v2;

    v1.push_back(make_pair(n, n));
    v2.push_back(make_pair(n, n));

    set< pair<int, int> > s;
    s.insert(v1[v1.size() - 1]);

    for(int i = 0; i< n; i++)
    {
        if(i % 2)
        {
            switch(inp[i])
            {
                case 'U':
                            v1.push_back(make_pair(v1[v1.size() - 1].first - 1, v1[v1.size() - 1].second));
                            break;
                case 'D':
                            v1.push_back(make_pair(v1[v1.size() - 1].first + 1, v1[v1.size() - 1].second));
                            break;
                case 'L':
                            v1.push_back(make_pair(v1[v1.size() - 1].first, v1[v1.size() - 1].second - 1));
                            break;
                case 'R':
                            v1.push_back(make_pair(v1[v1.size() - 1].first, v1[v1.size() - 1].second + 1));
                            break;
            }
            s.insert(v1[v1.size() - 1]);
        }
        else
        {
            switch(inp[i])
            {
                case 'U':
                            v2.push_back(make_pair(v2[v2.size() - 1].first - 1, v2[v2.size() - 1].second));
                            break;
                case 'D':
                            v2.push_back(make_pair(v2[v2.size() - 1].first + 1, v2[v2.size() - 1].second));
                            break;
                case 'L':
                            v2.push_back(make_pair(v2[v2.size() - 1].first, v2[v2.size() - 1].second - 1));
                            break;
                case 'R':
                            v2.push_back(make_pair(v2[v2.size() - 1].first, v2[v2.size() - 1].second + 1));
                            break;
            }
            s.insert(v2[v2.size() - 1]);
        }

    }
    cout<<s.size()<<endl;
    return 0;
}

