#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vector<string> a,string s)
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
    string dfa[] = {"Aaagmnrs", "TopCoder", "anagrams", "Drop Cote"};
    vector<string> sorted_inp;
    vector<string> inp{"Aaagmnrs", "TopCoder", "anagrams", "Drop Cote"};

    for(int i = 0; i < inp.size(); i++)
    {
        sorted_inp.push_back(inp[i]);
        sort(all(sorted_inp[i]));
        sorted_inp[i].erase(remove(all(sorted_inp[i]), ' '), sorted_inp[i].end());
    }

    display_vi(sorted_inp, " ");
    return 0;
}