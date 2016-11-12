#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

void display(vector<pair<char, int> > &out)
{
    for(int i = 0; i < out.size(); i++)
    {
        cout<<out[i].first<<"\t"<<out[i].second<<endl;
    }
}

/*
    Code Here!
*/

int binomialCoeff(int n, int k)
{
    int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;
 
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}

int main()
{
    int n;
    string word, sleep;

    cin>>n;
    cin>>word>>sleep;

    int t;
    cin>>t;

    while(t--)
    {
        vector<pair<char, int> > inp1, inp2;
        int x, y;
        cin>>x>>y;
        x--; y--;

        for(int i = x; i <= y; i++)
        {
            sleep[i] = sleep[i] - 48;
            if(sleep[i] == 0)
                inp1.push_back(make_pair(word[i], sleep[i]));
            else
                inp2.push_back(make_pair(word[i], sleep[i]));
        }

        ll count_inp1, count_inp2;

        if(inp1.size() == 0)
            count_inp1 = 0;
        else
            count_inp1 = binomialCoeff(inp1.size(), 2) % MOD;

        if(inp2.size() == 0)
            count_inp2 = 0;
        else
            count_inp2 = binomialCoeff(inp2.size(), 2) % MOD;

        ll diff_count = 0;
        string alpha = "abcdefghijklmnopqrstuvwxyz";

        for(int i = 0; i < alpha.length(); i++)
        {
            int c1, c2;
            c1 = c2 = 0;

            for(int j = 0; j < inp1.size(); j++)
            {
                if(inp1[j].first == alpha[i])
                    c1++;
            }

            for(int j = 0; j < inp2.size(); j++)
            {
                if(inp2[j].first == alpha[i])
                    c2++;
            }
            diff_count += (c1 * c2) % MOD;
        }

        ll res = (count_inp1 + count_inp2 + diff_count) % MOD;

        /*display(inp1);
        display(inp2);
        cout<<count_inp1<<"\t"<<count_inp2<<endl;*/
        cout<<res<<endl;
    }
        
    return 0;
}

