#include <iostream>
#include <cstring>

using namespace std;

long long two_d[300];

long long fx(long long n, long long m)
{
    if(n == 1)
        return 1;
    if(n < 1)
        return 0;

    if(two_d[n] != 0)
        return two_d[n];
    two_d[n] = fx(n - 1, m) + fx(n - m, m);
    return two_d[n];
}

int main()
{
    ios::sync_with_stdio(false);
    long long t;
    cin>>t;

    while(t--)
    {
        long long n, p, m;
        cin>>n>>p>>m;

        long long x, y;
        long long tot_sum = 0;

        memset(two_d, 0, 300);
        cin>>x>>y;

        if(y < x)
        {
            cout<<y*p<<endl;
            continue;
        }
        else
        {
            if(m == 1)
            {
                tot_sum = x;
                p--;
                tot_sum += (y * p);
            }
            else
            {
                long long sum = fx(n + 1, m);
                
                if(p > sum)
                {                    
                    tot_sum = x * sum;
                    p = p - sum;
                    tot_sum += (y * p);
                }
                else
                {
                    tot_sum = x * p;
                    p = 0;
                }
            }                
        }

        cout<<tot_sum<<endl;
    }
    return 0;
}