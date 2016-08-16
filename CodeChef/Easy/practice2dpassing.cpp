#include <iostream>
#include <stdio.h>

using namespace std;

/*void incr(int n, int m, int a[][m])
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            a[i][j]++;
    }   
}*/

// this is a very ugly truth for c++ passing 2d array of arbitrary size is hard
    // in order to overcome this proble we can convert it into a 1d array
    // and use like a[i * c + j] (this is the best solution that I found on the internet)
void display(int n, int m, int * a)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cout<<a[i * m + j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    int a[n][m];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m ; j++)
            cin>>a[i][j];
    }

    //incr(n, m, a);
    display(n, m, (int *) a);
    return 0;
}