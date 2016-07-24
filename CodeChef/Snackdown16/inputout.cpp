#include <vector>
#include <iostream>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    /*vector<int> arr;

    arr.reserve(n);
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    cout<<"\nTaken input"<<endl;
    //display(arr);*/

    int arr[n];

    for(int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    cout<<"\nTaken input"<<endl;
    return 0;
}