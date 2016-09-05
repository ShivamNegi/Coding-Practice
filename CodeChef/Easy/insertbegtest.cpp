#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int nos;
    cin>>nos;

    vector<int> arr;

    for(int i = 0; i < nos; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    display(arr);
    reverse(arr.begin(), arr.end());
    arr.pop_back();
    display(arr);

    return 0;
}