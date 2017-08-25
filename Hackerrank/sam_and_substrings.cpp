#include <bits/stdc++.h>
#define MOD 100000007
#define ll long long

using namespace std;

void display(vector<ll> arr)
{
    for(ll i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

long long find(vector<ll> arr)
{
    long long res = 0;
    
    for(ll i = 1; i <= arr.size(); i++)
    {
        for(ll j = 0; j <= arr.size() - i; j++)
        {
            long long val = 0, counter = i - 1;

            for(ll k = 0; k < i; k++)
            {
                val = val + arr[j + k] * pow(10, counter--);
            }
            res = (res + (val % MOD)) % MOD;
        }
    }
    
    return res;
}

int main()
{
    ll no;
    cin>>no;

    vector<ll> arr;
    while(no > 0)
    {
        arr.insert(arr.begin(), no % 10);
        no /= 10;
    }

    cout<<find(arr)<<endl;
    return 0;
}