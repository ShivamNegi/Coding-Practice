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

int arr[1000][1000];

void calc(vector<int> & inp)
{
    for(int i = 0; i < inp.size(); i++)
    {
        for(int j = i + 1; j < inp.size(); j++)
        {
            inp[j] =  inp[i] - arr[i][j];
            if(j != i -1 && abs(inp[j] - inp[j - 1]) == arr[j][j - 1])
            {
                continue;
            }
            else
            {
                inp[j] = - inp[j];
            }

        }
    }
}

void display2d(int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void clear(vector<int> & inp)
{
    for(int i = 0; i < inp.size(); i++)
        inp[i] = 0;
}

int main()
{
    int n, q;
    cin>>n>>q;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cin>>arr[i][j];
    }

    vector<int> inp(n);
    inp[0] = 0;

    calc(inp);
    display_vi(inp, " ");

    while(q--)
    {
        clear(inp);
        int row;
        cin>>row;
        for(int i = 0; i < n; i++)        
        {
            cin>>arr[row - 1][i];
            arr[i][row - 1] = arr[row - 1][i];
        }

        display2d(n);
        calc(inp);
        display_vi(inp, " ");
    }
    return 0;
}


