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

void display(vector< pair<int, int> >& inp_arr)
{
    for(int i = 0; i < inp_arr.size(); i++)
    {
        cout<<inp_arr[i].first<<" ";
    }
    cout<<"\n";
    for(int i = 0; i < inp_arr.size(); i++)
    {
        cout<<inp_arr[i].second<<" ";
    }
    cout<<endl;
}

void create(string inp, vector< pair<char, bool> >& inp_arr)
{
    for(int i = 0; i < inp.length(); i++)
    {
        inp_arr[i].first = inp[i];
        inp_arr[i].second = false;
    }
}

int match(vector< pair<char, bool> >& inp_arr, string inp)
{
    bool flag;
    int i;
    for(i = 0; i < inp_arr.size() - inp.length() + 1; i++)
    {
        flag = true;
        for(int j = 0; j < inp.length(); j++)
        {
            if(inp[j] != inp_arr[j + i].first || inp_arr[j + i].second)
            {
                flag = false;
                break;
            }
        }

        if(flag)
        {
            for(int j = i; j < inp.length(); j++)
                inp_arr[j].second = true;
            return i;
        }
    }

    return -1;
}

int main()
{
    string inp;
    cin>>inp;
    replace(all(inp), ' ', '_');

    vector< pair<char, bool> > inp_arr(inp.length());
    create(inp, inp_arr);

    int t;
    cin>>t;

    vector<string> k;
    vector< pi > ord;

    for(int i = 0; i < t; i++)
    {
        string str;
        cin>>str;
        replace(all(str), ' ', '_');
        k.push_back(str);
        ord.push_back(make_pair(str.length(), i));
    }

    sort(all(ord));
    reverse(all(ord));
    vector< pi > out(t);

    for(int i = 0; i <  k.size(); i++)
    {
        int j = ord[i].second;
        int p_find = match(inp_arr, k[j]);

        out[j].first = p_find;
        out[j].second = j;
    }

    sort(all(out));

    for(int i = 0; i < t; i++)
    {
        if(out[i].first > -1)
        {
            cout<<out[i].second<<" ";
        }
    }
    cout<<endl;
    return 0;
}

