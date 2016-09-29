#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }
    else
        return gcd(b, a % b);
}

int main()
{
    int n;
    cin>>n;

    vector<int> a;

    for(int i = 0; i < n; i++)
    {
        a.push_back(i + 1);
    }

    int t;
    t = n;

    while(t--)
    {
        int x, y;
        x = y = (n - t);
    
            if(true)
            {
                x--; y--;
                long long tot_sum = 0;
                for(int i = x; i <= y; i++)
                {
                    for(int j = 1; j <= a[i]; j++)
                    {
                        tot_sum += (j / gcd(a[i], j)) % MOD;
                    }
                }
                cout<<n - t<<"\t"<<tot_sum<<endl;
            }}
    return 0;
}