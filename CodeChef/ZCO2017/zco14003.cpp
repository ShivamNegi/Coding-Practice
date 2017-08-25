#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<long long> arr;
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    sort(arr.begin(), arr.end());
    long long profit = 0;

    for(int i = 0; i < n; i++)
    {
        long long temp;
        temp = arr[i] * (n - i);
        if(temp > profit)
            profit = temp;
    }

    cout<<profit<<endl;

    return 0;
}