#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    vector<int> a;

    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        a.push_back(no);
    }

    int x, y;
    cin>>x>>y;

    cout<<accumulate(a.begin() + x - 1, a.begin() + y, 0)<<endl;

 return 0;
}