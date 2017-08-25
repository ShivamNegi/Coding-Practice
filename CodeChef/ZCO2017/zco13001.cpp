#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<ll> arr;
    for(int i = 0; i < n; i++)
    {
        ll no;
        cin>>no;
        arr.push_back(no);
    }

    sort(arr.begin(), arr.end());
    ll s1, s2, res;
    s1 = s2 = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        s1 = s1 + i * arr[i];
        s2 = s2 + (n - 1 - i) * arr[i];
    }

    res = s1 - s2;

    cout<<res<<endl;
    return 0;
}   