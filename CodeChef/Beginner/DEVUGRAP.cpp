#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        long long int a[n];
        long long int sum = 0;

        for(int i = 0; i < n; i++)
            {
                cin>>a[i];

                if(a[i] <= k / 2)
                {
                    sum += k - a[i];
                }
                else
                {
                    int a1, b;
                    a1 = a[i] % k;
                    b = k - a1;

                    if(a1 < b)
                        sum += a1;
                    else
                        sum += b;
                }
            }

        cout<<sum<<endl;
    }
}