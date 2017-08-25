#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector< pair<int, int> > arr;
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        arr.push_back(make_pair(no, i + 1));
    }

    ll total;
    cin>>total;

    sort(arr.begin(), arr.end());

    ll res = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        ll tot_cost = arr[i].first * arr[i].second;
        if(tot_cost <= total)
        {
            total -= tot_cost;
            res += arr[i].second;
        }
        else
        {
            res += total / arr[i].first;
            break;
        }
    }

    cout<<res<<endl;

    return 0;
}