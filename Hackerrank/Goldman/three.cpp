#include <bits/stdc++.h>
#define ll long long

using namespace std;

int memoize[1001][10];

void clear()
{
    for(int i = 0; i < 1001; i++)
    {
        for(int j = 0; j < 10; j++)
            memoize[i][j] = -1;
    }
}

int fx(vector<int> & arr, int pos, int profit, int k)
{
    if(k == 0)
        return profit;
    if(pos >= arr.size())
        return profit;
    int max_val = 0;
    if(memoize[pos][k] != -1)
        return memoize[pos][k];
    for(int i = pos; i < arr.size(); i++)
    {
        int val = arr[i];
        for(int j = i + 1; j < arr.size(); j++)
        {
            if(val <= arr[j])
                max_val = max(max_val, profit + fx(arr, j + 1, arr[j] - val, k - 1));
        }
    }

    memoize[pos][k] = max_val;
    return max_val;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        clear();
        int k, n;
        cin>>k>>n;

        vector<int> arr;
        vector<bool> visited;
        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
            visited.push_back(false);
        }

        cout<<fx(arr, 0, 0, k)<<endl;
    }

    return 0;
}