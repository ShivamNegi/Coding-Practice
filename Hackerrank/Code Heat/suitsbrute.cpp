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

        long long int no[n];
        long long int count = 0;

        for(int i = 0; i < n; i++)
        {
            cin>>no[i];
        }

        for(int i = 0; i < n; i++)
        {
            long long int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum += no[j];

                if(sum == 0)
                    count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}