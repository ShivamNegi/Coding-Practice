#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)
#define MOD 1000000007

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

/*
    Code Here!
*/

int main()
{
    int t;
    //cin>>t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        //cin>>n;
        scanf("%d", &n);

        vector<ll> arr, out;

        for(int i = 0; i < n; i++)
        {
            ll no;
            //cin>>no;
            scanf("%lld", &no);

            arr.push_back(no);
            out.push_back(1);
        }

        sort(all(arr));
        bool two_d[n][n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                two_d[i][j] = false;
        }

        for(int i = n - 2; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(two_d[i][j])
                    continue;

                if(arr[j] % arr[i] == 0)
                    {
                        out[i] += (out[j] + out[j] - 1);
                        two_d[i][j] = true;

                        for(int k = j + 1; k < n; k++)
                            two_d[i][k] = two_d[j][k];
                    }
            }
        }

        //cout<<accumulate(all(out), 0) % MOD<<endl;
        ll res = 0;

        for(int i = 0; i < n; i++)
        {
            res %= MOD;
            res += out[i];
        }

        printf("%lld\n", res);
    }
    return 0;
}

