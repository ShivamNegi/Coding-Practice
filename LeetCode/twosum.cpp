#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
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

    int val;    
    cin>>val;

    sort(arr.begin(), arr.end());

    int j = arr.size() - 1, i;
    for(i = 0;;)
    {
        int sum = arr[i] + arr[j];
        if(sum > val)
        {
            j--;
        }
        else if(sum < val)
            i++;
        else
            break;        
    }

    cout<<i<<" "<<j<<endl;

    return 0;
}