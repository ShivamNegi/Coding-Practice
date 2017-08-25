#include <iostream>

using namespace std;

int binary_search(int arr[], int key, int size)
{
    int low, high, mid;

    low = 0;
    high = size - 1;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(key < arr[mid])
            high = mid - 1;
        else if(key > arr[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int main()
{
    int n;
    cout<<"Enter the no of numbers: ";
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int key;
    cout<<"Enter the number to be searched: ";
    cin>>key;

    int pos;
    if((pos = binary_search(arr, key, n)) == -1)
        cout<<"Not found.\n";
    else
        cout<<"Found at "<<pos<<endl;

    return 0;
}