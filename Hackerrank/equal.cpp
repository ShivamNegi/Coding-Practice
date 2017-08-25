#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

ll dp(vector<ll> arr)
{
    ll val = arr[arr.size() - 1], counter = 0;
    ll nos[] = {1, 2, 5}, res[val + 1];
    
    res[0] = 0;
    for(ll i = 1; i < val + 1; i++)
        res[i] = 9999;
    
    for(ll i = 1; i <= val; i++)   
    {
        for(ll j = 0; j < 3; j++)
        {
            if(nos[j] <= i && res[i - nos[j]] + 1 < res[i])
                res[i] = res[i - nos[j]] + 1;
        }
    }
    
    for(ll i = 0; i < arr.size(); i++)
        counter += res[arr[i]];
    
    return counter;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t;
    cin>>t;
    
    while(t--)
    {
        ll n;
        cin>>n;
        
        vector<ll> arr;        
        for(ll i = 0; i < n; i++)
        {
            ll no;
            cin>>no;
            arr.push_back(no);
        }
        
        sort(arr.begin(), arr.end());
        ll val = arr[0];
        for(ll i = 0; i < arr.size(); i++)
        {
            arr[i] -= val;
        }
        ll counter = dp(arr);
        cout<<counter<<endl;
    }
        
    return 0;
}

