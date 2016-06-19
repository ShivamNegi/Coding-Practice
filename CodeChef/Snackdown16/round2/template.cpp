#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isprime(int no)
{
    for(int i = 2; i < sqrt(no); i++)
    {
        if(no % i == 0)
        {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b)
{
    if(a % b == 1)
        return b;
    else
        return (gcd(b, a % b));
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a, primes;
        int even = 0;


        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            if(no % 2 == 0 && no != 2)
            {
                even++;
            }
            else if(isprime(no))
            {
                // primes++;
                // i need to check if the prime is already present
                if(find(primes))
                    primes.push_back(no);
            }
            else
                a.push_back(no);
        }

       
        int val;

        if(even > 0)
            val = max_size + primes.size() + 1;
        else
            val = max_size + primes.size();

        cout<<val<<endl;
    }
    return 0;
}