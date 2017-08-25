#include <iostream>
#define ll long long

using namespace std;

int main()
{
    ll n, h;
    cin>>n>>h;

    ll arr[n];
    for(ll i = 0; i < n; i++)
        cin>>arr[i];

    ll inp, ptr = 0;
    bool picked = false;
    cin>>inp;
    while(inp != 0)
    {
        if(inp == 1)
        {
            if(ptr != 0)
                ptr--;
        }
        else if(inp == 2)
        {
            if(ptr != n - 1)
                ptr++;
        }
        else if(inp == 3)
        {
            if(arr[ptr] != 0 && !picked)
            {
                arr[ptr]--;
                picked = true;
            }
        }
        else if(inp == 4)
        {
            if(arr[ptr] != h && picked)
            {
                arr[ptr]++;
                picked = false;
            }
        }
        cin>>inp;
    }

    for(ll i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
