#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--)
    {
        long long n, b;
        cin>>n>>b;

        long long max, val;
        max = 0;

        val = n % b;
        n = n - val;
        while(n >= b)
        {
            long long temp = 0;
            temp = (n / b) * val;

            if(temp > max)
                max = temp;

            n -= b;
            val += b;                
        }

        cout<<max<<endl;
    }
    return 0; 
}