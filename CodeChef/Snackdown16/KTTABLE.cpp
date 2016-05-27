#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int a[n], b[n];

        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        for(int i = 0; i < n; i++)
            {cin>>b[i];}

        int count = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0)
            {
                if(b[i] <= a[i])
                    count ++;
            }
            else
            {
                if(a[i - 1] + b[i] <= a[i + 1])
                {
                    count ++;
                }
            }            
        }

        cout<<count<<endl;        
    }
    return 0;
}