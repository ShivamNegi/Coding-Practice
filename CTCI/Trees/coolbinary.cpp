#include <iostream>

using namespace std;

int binarysearch(int a[], int data, int size)
{
    int l = 0, h = size;

    while(l <= h)
    {
        int mid = (l + h) / 2;

        if(a[mid] < data)
            l = mid + 1;
        else if(a[mid] > data)
            h = mid - 1;     
        else
            return mid;   
    }
    return -1;
}

int firstpos(int a[], int data, int minpos, int size)
{
    minpos = binarysearch(a, data, size);
    if(minpos == -1)
        return size;
    else
    {
        int b[minpos + 1];
        for(int i = 0; i <= minpos; i++)
            b[i] = a[i];
        b[minpos] = data + 1;
        int something = firstpos(b, data, size, minpos + 1);
        return something>minpos? minpos:something;
    }
}

int main()
{
    int a[] = {1, 1, 1, 2, 2, 3, 4, 4, 4, 4, 5};
    int size = 11;
    int x;
    cin>>x;
    
    cout<<firstpos(a, x, size, size)<<endl;
    return 0;
}