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

bool isalternate(string inp)
{
    char prev = inp[0];
    for(int i = 1; i < inp.length(); i++)
    {
        if(prev == inp[i])
            return false;
        prev = inp[i];
    }
    return true;
}

int main()
{
    int n;
    cin>>n;

    string inp;
    cin>>inp;

    while(true)
    {
        set<char> rep;
        bool flag = false;

        for(int i = 0; i < inp.length() - 1; i++)
        {
            if(inp[i] == inp[i + 1])
                {
                    rep.insert(inp[i]);
                    flag = true;
                }
        }

        for(set<char>:: iterator it = rep.begin(); it != rep.end(); it ++)
            inp.erase(remove(inp.begin(), inp.end(), *it), inp.end());        

        if(!flag)
            break;
    }

    if(inp.size())
    {
        set<char> eles(all(inp));
        string rem = "";

        for(set<char>:: iterator it = eles.begin(); it != eles.end(); it++)
            rem += *it;
        

        set< pair<char, char> > mem;
        int max_len = 0;
        do
        {
            pair<char, char> val(make_pair(rem[0], rem[1]));
        
            //cout<<val.first<<"\t"<<val.second<<endl;
            if(mem.find(val) != mem.end())
            {
                continue;
            }                
            else
            {
                string test = "";
                for(int i = 0; i < inp.length(); i++)
                {   
                    if(inp[i] == val.first || inp[i] == val.second)
                        test += inp[i];
                }
                
                if(isalternate(test))
                    max_len = max(max_len, (int)test.length());
                mem.insert(val);
                swap(val.first, val.second);
                mem.insert(val);
            }                
        }while(next_permutation(all(rem)));
        cout<<max_len<<endl;
    }
    else
        cout<<"0\n";
        
    return 0;
}

