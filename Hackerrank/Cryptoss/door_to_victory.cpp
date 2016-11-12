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

vector<string> a;
stack<int> b;
vector<int> out;
string inp;

void display(stack<int> k)
{
    while(!k.empty())
            {
                int w = k.top();
                out.push_back(w);
                k.pop();
            }
}

int victory_door(string curr)
{
    if(curr == inp)
    {
        display(b);
        return 1;
    }
    for(int i = 0; i < a.size(); i++)
    {
        if(inp.find(a[i]) != -1)
        {
            string n_curr = curr + a[i];
            if(inp.find(n_curr) != -1)
            {
                b.push(i);
                if(victory_door(n_curr))
                    break;
                b.pop();
            }
        }
    }
    return 0;
}

int main()
{
    cin>>inp;

    int t;
    cin>>t;

    for(int i = 0; i < t; i++)
    {
        string str;
        cin>>str;
        a.push_back(str);
    }

    victory_door("");
    reverse(all(out));
    display_vi(out, " ");
    return 0;
}