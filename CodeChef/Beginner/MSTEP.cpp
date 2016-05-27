#include<iostream>
#include<vector>
#include<stdlib.h>

using namespace std;

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int a[n][n];
        int row[n * n], col[n * n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin>>a[i][j];
                row[a[i][j] - 1] = i;
                col[a[i][j] - 1] = j;
            }
        }

        int sum = 0;

        for(int i = 0; i < (n * n) - 1; i++)
        {
            sum += abs(row[i + 1] - row[i]) + abs(col[i + 1] - col[i]);
        }

        cout<<sum<<endl;
    }
    return 0;
}