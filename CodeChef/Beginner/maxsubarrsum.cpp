#include <iostream>

using namespace std;

int mmsum(int a[], int size)
{
    int maxsum = a[0], currsum = a[0];
    for(int i = 1; i < size; i++)
    {
        currsum += a[i];
        if(currsum > maxsum)
        {
            maxsum = currsum;
        }
        if(currsum < 0)
            currsum -= a[i];
    }
    return maxsum;
}

int main()
{
    int size;
    cin>>size;

    int a[size];
    for(int i = 0; i < size; i++)
    {
        cin>>a[i];
    }

    cout<<mmsum(a, size)<<endl;
    return 0;
}