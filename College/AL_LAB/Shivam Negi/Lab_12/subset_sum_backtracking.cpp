#include <iostream>

using namespace std;

void display(bool vis[], int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        if(vis[i])
            cout<<a[i]<<"\t";
    }
    cout<<endl;
}

void backtracking(int a[], int d, bool vis[], int sum, int size, int pos)
{
    if(sum == d)
        display(vis, a, size);
    else if(sum > d)
        return;
    else
    {
        for(int i = pos; i < size; i++)
        {
            if(!vis[i])
            {
                sum += a[i];
                vis[i] = true;
                backtracking(a, d, vis, sum, size, i + 1);
                sum -= a[i];
                vis[i] = false;
            }
        }
    }
}

int main()
{
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    bool vis[n];
    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        vis[i] = false;
    }

    int d;

    cout<<"Enter the required sum: ";
    cin>>d;

    backtracking(a, d, vis, 0, n, 0);

    return 0;
}