#include <iostream>
#define INF 10000009

using namespace std;

// O(n)
void merge(int a[], int l, int m, int r)
{
 int lsize = m - l;
 int rsize = r - m;
 int left[lsize + 1], right[rsize + 1];

 for(int i = 0; i < lsize; i++)
    left[i] = a[l + i];

 for(int i = 0; i < rsize; i++)
    right[i] = a[m + i];

 // assigning sentinel
 left[lsize] = INF;
 right[rsize] = INF;

 int lcounter, rcounter;
 lcounter = rcounter = 0;

 for(int i = 0; i < lsize + rsize; i++)
    if((left[lcounter] < right[rcounter] && left[lcounter] != INF) || right[rcounter] == INF)
        a[l + i] = left[lcounter++];
    else
        a[l + i] = right[rcounter++];
}

// O(log n)
void mergesort(int a[], int l, int r)
{
    if(l < r - 1)
    {
        int p = (l + r) / 2;
        mergesort(a, l, p);
        mergesort(a, p, r);
        merge(a, l, p, r);
    }
}

void display(int a[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<a[i]<<"\t";
    cout<<endl;
}

int main()
{
    int n;

    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];

    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++)
        cin>>a[i];

    display(a, n);
    // O(n log n)
    mergesort(a, 0, n);
    display(a, n);

    return 0;
}