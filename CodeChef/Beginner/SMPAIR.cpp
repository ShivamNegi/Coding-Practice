#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        sort(arr.begin(), arr.end());
        cout<<arr[0] + arr[1]<<endl;
    }
    return 0;
}