#include <iostream>
#include <vector>

using namespace std;

void display(vector<pair<int, int> > a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }

}

int main()
{
    int x, y, m;
    cin>>x>>y>>m;

    vector<pair<int, int> > a(m + 1);

    a[0].first = x; a[0].second = y;
    for(int i = 1; i <= m; i++)
    {
        a[i].first = a[i - 1].first - (a[i - 1].first) / 2;
        a[i].second = a[i - 1].second - (a[i - 1].second - 1) / 2;
    }

    display(a);

    return 0;
}