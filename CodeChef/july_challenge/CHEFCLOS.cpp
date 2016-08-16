#include <iostream>
#include <vector>

using namespace std;

int combination(int n, int k)
{
    if(k == 1)
        return n;
    if(n == k)
        return 1;
    return combination(n - 1, k) + combination(n - 1, k - 1);
}

int gcd(int a, int b)
{
    if(a % b == 0)
        return b;
    else
        return gcd(b, a % b);
}

bool notpresent(vector<int> a, int val)
{
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == val)
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k, l;
        cin>>n>>k>>l;

        vector<int> a, gcds;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
        }

        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                int val = gcd(a[i], a[j]);
                // insert only if gcd is not already present
                if(notpresent(gcds, val))
                    gcds.push_back(val);
            }
        }

        int counter = 0;
        for(int i = 0; i < gcds.size(); i++)
        {
            if(notpresent(a, gcds[i]))
                counter++;
        }

        cout<<combination(counter, k)<<endl;
    }
    return 0;
}