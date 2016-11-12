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
int n, m;

void display(vvi& inp)
{
    for(int i = 0; i < inp.size(); i++)
    {
        for(int j = 0; j < m; j++)            
            cout<<inp[i][j];
        cout<<endl;
    }
    cout<<endl;
}

void color(vvi& inp, int r, int c, int x, int y, int ch)
{
    if(r < 0 || r >= n || c >= m || c < 0)
        return;
    else
    {
        if(x < 0)
            return;
        if(y < 0)
            return;
        inp[r][c] = ch;

        color(inp, r - 1, c, x, y - 1, ch);
        color(inp, r, c - 1, x - 1, y, ch);
        color(inp, r + 1, c, x, y - 1, ch);
        color(inp, r, c + 1, x - 1, y, ch);
    }
}

int counter;
void bomb_counter(vvi& inp, int r, int c, int x, int y)
{
    if(r < 0 || r >= n || c >= m || c < 0)
        return;
    else
    {
        if(x < 0)
            return;
        if(y < 0)
            return;
        if(inp[r][c] == 1)
            counter++;
        bomb_counter(inp, r - 1, c, x, y - 1);
        bomb_counter(inp, r, c - 1, x - 1, y);
        bomb_counter(inp, r + 1, c, x, y - 1);
        bomb_counter(inp, r, c + 1, x - 1, y);
    }
}

void correct(int &r, int &c, int &x, int &y)
{
    r--;
    c--;
    x /= 2;
    y /= 2;
}

int main()
{
    cin>>n>>m;

    vvi inp(n);

    for(int i = 0; i < n; i++)
    {
        string sen;
        cin>>sen;
        for(int j = 0; j < m; j++)
        {
            if(sen[j] == '*')
                inp[i].push_back(1);
            else
                inp[i].push_back(0);
        }
    }

    //display(inp);
    int t;
    cin>>t;

    while(t--)
    {
        int choice, r, c, x, y;
        cin>>choice>>r>>c>>x>>y;

        correct(r, c, x, y);
        switch(choice)
        {
            case 1:
                    color(inp, r, c, x, y, 1);
                    break;
            case 2:                    
                    color(inp, r, c, x, y, 0);
                    break;
            case 3:
                    counter = 0;
                    cout<<counter<<endl;
                    bomb_counter(inp, r, c, x, y);
                    cout<<counter<<endl;
                    break;
        }
        //display(inp);
    }

    return 0;
}

