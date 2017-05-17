#include <bits/stdc++.h>

using namespace std;

int main()
{
    string inp;
    cin>>inp;

    vector< vector<char> > mut(inp.length());

    mut[0].push_back('$');
    mut[0].push_back('P');
    mut[1].push_back('A');
    mut[2].push_back('/');
    mut[2].push_back('&');
    mut[2].push_back('S');


    string base = "";
    for(int i = 0; i < inp.length(); i++)
    {
        base = base + mut[i].back();
        mut[i].pop_back();
    }
    
    cout<<base<<endl;
    return 0;
}

