#include <bits/stdc++.h>

using namespace std;

int max_prod_arr(vector<int> & arr)
{
    int val, max_val;
    val = max_val = arr[0];

    // checking for max prod subarry in forward direction.
    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i] == 0)
            val = 0;
        else
        {
            if(val == 0)
                val = arr[i];
            else
                val = val * arr[i];
        }
        max_val = max(val, max_val);
    }

    // checking for max prod subarry in reverse direction.
    val = arr[arr.size() - 1];
    for(int i = arr.size() - 2; i >= 0; i--)
    {
        if(arr[i] == 0)
            val = 0;
        else
        {
            if(val == 0)
                val = arr[i];
            else
                val = val * arr[i];
        }
        max_val = max(val, max_val);
    }

    // This loop is for the corner case when input: [-3,0,1,-2]
    for(int i = 0; i < arr.size(); i++)
        max_val = max(max_val, arr[i]);
    return max_val;
}

int main()
{
    int len;
    cin>>len;

    vector<int> arr;
    for(int i = 0; i < len; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    int res = max_prod_arr(arr);
    cout<<res<<endl;
    return 0;
}