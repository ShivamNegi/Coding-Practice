#include <iostream>

using namespace std;

long long int mmsum(int a[], int size)
{
    long long int currsum = 0, totsum = 0;

    for(int i = 0; i < size; i++)
    {
        currsum += a[i];
        if(currsum < 0)
            currsum = 0;
        if(totsum < currsum)
            totsum = currsum;
    }
    return totsum;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int size;
        cin>>size;
        int a[size];
        long long int unsum = 0;
        bool flag = true;

        for(int i = 0; i < size; i++)
        {            cin>>a[i];  
            if(a[i] > 0)
                flag = false;
        }

        if(!flag)
        {
            for(int i = 0; i < size; i++)
            {
                if(a[i] > 0)
                    unsum += a[i];
            }

            long long int consum = mmsum(a, size);
            cout<<consum<<" "<<unsum<<endl;
        }
        else
        {
            unsum = a[0];
            for(int i = 0;i < size; i++)
            {
                if(a[i] > unsum)
                    unsum = a[i];
            }

            cout<<unsum<<" "<<unsum<<endl;
        }               
    }
    return 0;
}