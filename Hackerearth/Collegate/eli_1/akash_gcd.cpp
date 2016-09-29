#include <iostream>
#include <vector>

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
        int no;
        cin>>no;
        a.push_back(no);
    }

    int t;
    cin>>t;

    while(t--)
    {
        char ch;
        cin>>ch;
        int x, y;
        cin>>x>>y;

        if(ch == 'C')
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
            cout<<tot_sum<<endl;
        }
        else
        {
            x--;
            a[x] = y;
        }
    }
    return 0;
}