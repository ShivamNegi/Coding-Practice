#include <iostream>

using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    int a[n], candies[n];

    for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            if(i == 0)
                candies[i] = 1;
            else if(a[i] > a[i - 1])
                candies[i] = candies[i - 1] + 1;
            else
                candies[i] = 1;
        }
    for(int i = n - 2; i >= 0; i--)
    {
        if(a[i] > a[i + 1])
            if(candies[i] > candies[i + 1])
                continue;
            else
                candies[i] = candies[i + 1] + 1;
    }

    long long int sum = 0;
    for(int i = 0; i < n; i++)
        {sum += candies[i];}

    //display(candies, n);
    cout<<sum<<endl;
    return 0;
}