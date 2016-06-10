#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int min = 100000, a[n];

        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(a[i] < min)
                min = a[i];
        }

        unsigned long long int val = min * (n - 1);
        //cout<<min * (n - 1)<<endl;
        printf("%llu\n", val);
    }
    return 0;
}