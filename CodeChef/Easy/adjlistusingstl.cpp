#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x, y, n;

    cout<<"How many edges?";
    cin>>n;

    vector< vector< pair<int, int> > > g(n);
    for(int i = 0; i < n; i++)
    {
        cin>>x>>y;
        g[x].push_back(make_pair(y, 1));
    }

    for(int i = 0; i < g.size(); i++)
    {        
        for(int j = 0; j < g[i].size(); j++)
            cout<<i<<"\t"<<g[i][j].first<<"\n";        
        cout<<endl;
    }

    return 0;
}