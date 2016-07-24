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

        long long int no[n], temp[n];
        temp[0] = 0;

        for(int i = 0; i < n; i++)
        {
            cin>>no[i];

            if(i == 0)
                temp[i + 1] = no[i];
            else
                temp[i + 1] = no[i] + temp[i];
        }



    }
    return 0;
}