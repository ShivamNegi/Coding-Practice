#include <iostream>

using namespace std;

void insertele(int a[], int ele, int pos, int size)
{
    for(int i = size; i > pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos] = ele;
}

void incr(int a[], int size)
{
    for(int i = 0; i < size; i++)
        a[i]++;
}

void display(int a[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    int a[5], size;

    for(int i = 0; i < 4; i++)
    {
        cin>>a[i];
    }

    size = 4;
    display(a, 4);
    insertele(a, 23, 2, size);
    size++;
    display(a, size);
    return 0;
}