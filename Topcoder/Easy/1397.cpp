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

class Aaagmnrs
{
    vector<string> anagrams(vector<string> inp)
    {
        vector<string> sorted_inp;

        for(int i = 0; i < inp.size(); i++)
        {
            sorted_inp.push_back(inp[i]);
            sort(all(sorted_inp[i]));
            sorted_inp[i].erase(remove(all(sorted_inp[i]), ' '), sorted_inp[i].end());
        }

        for(int i = 1; i < inp.size(); i++)
        {
            bool flag = false;
            int j;
            for(j = 0; j < i; j++)
            {
                if(sorted_inp[j] == sorted_inp[i])
                {
                    flag = true;
                    break;
                }
            }
            if(flag)
            {
                inp.erase(inp.begin() + j);
                sorted_inp.erase(sorted_inp.begin() + j);
            }
        }

        return inp;
    }
};