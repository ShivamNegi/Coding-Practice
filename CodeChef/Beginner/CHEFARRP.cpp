#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        unsigned long int arr[n], number = n;

        for(int i = 0; i < n; i++)
        {            cin>>arr[i];        }

        unsigned long int sum, prod;

        for(int i = 0; i < n; i++)
        {
            sum = prod = arr[i];
            for(int j = i + 1; j < n; j++)
            {
                sum += arr[j];
                prod *= arr[j];

                if(sum == prod)
                    number++;
            }
        }

        cout<<number<<endl;

    }

    return 0;
}