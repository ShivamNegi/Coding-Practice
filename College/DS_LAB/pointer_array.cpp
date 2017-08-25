#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter the no of numbers: ";
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];

    int * p = arr;
    for(int i = 0; i < n; i++)
        cout<<*(p + i)<<" ";

    cout<<endl;

    return 0;
}