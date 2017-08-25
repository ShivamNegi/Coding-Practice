#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

typedef vector<ll> vi;

/*
    Code Here!
*/

int binarys(vi arr, int no)
{
    int l, m, u;
    l = 0;
    u = arr.size() - 1;

    while(l <= u)
    {
        m = (l + u) / 2;
        if(arr[m] < no)
            l = m + 1;
        else if(arr[m] > no)
            u = m - 1;
        else
            return m;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n, l, a, b;
        cin>>n>>l>>a>>b;

        vi arr;
        for(ll i = 0; i < n; i++)
        {
            ll no;
            cin>>no;
            arr.push_back(no);
        }

        arr.push_back(a);
        sort(all(arr));

        int pos = binarys(arr, a);

        while(arr[pos - 1] == a)
            pos--;

        int down = pos -1, up = pos + 1;

        vi lower, upper;
        for(int i = down; i > -1; i--)
            lower.push_back(arr[i]);
        for(int i = up; i < arr.size(); i++)
            upper.push_back(arr[i]);

        ll val = 0;

        down = 0;
        up = 0;
        while(true)
        {
            if(down == lower.size() && up == upper.size())
                break;
            else if(down == lower.size() && up < upper.size())
            {
                val = val + abs(a - upper[up++]);
            }
            else if(down < lower.size() && up == upper.size())
            {
                val = val + abs(a - lower[down++]);
            }
            else
            {
                ll n1, n2;
                n1 = abs(a - upper[up]);
                n2 = abs(a - lower[down]);
                if(n1 < n2)
                    val = val + abs(a - upper[up++]);
                else
                    val = val + abs(a - lower[down++]);
            }
            a += l;

            while(upper[up] < a)
            {
                lower.insert(lower.begin(), upper[up++]);
            }
        }

        cout<<val<<endl;
    }    
    return 0;
}