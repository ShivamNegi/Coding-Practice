#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vector< pi > a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i].first<<s<<a[i].second<<endl;
    cout<<endl;
}

/*
    Code Here!
*/

int main()
{
    int n, m;
    cin>>n>>m;

    int cn = n;
    vi b;
    vector< pi > c_a;
    ll marks = 0, time = 0;
    
    while(n--)
    {
        int no1, no2, no3;
        cin>>no1>>no2>>no3;

        b.push_back(no2);
        c_a.push_back(make_pair(no3, no2 - no1));
        marks += no1;
    }

    if(m > accumulate(all(b), 0) / b.size())
        cout<<"-1\n";
    else
    {
        sort(all(c_a));
        reverse(all(c_a));
        // display_vi(c_a, " ");
        for(int i = 0; i < c_a.size(); i++)
        {
            if(m * cn < marks + c_a[i].second)
            {
                // cout<<i<<"\t"<<time<<"\t"<<marks<<endl;  
                time += (cn * m - marks) / c_a[i].first;
                break;
            }   
            else
            {
                int val = c_a[i].second / c_a[i].first;
                time += val;
                marks += c_a[i].second;
            } 
        }        
        cout<<time<<endl;
    }
    return 0;
}

