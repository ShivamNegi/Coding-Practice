#include <iostream>
#include <vector>

using namespace std;

int min_hit(const vector<int>& arr, vector<int> res, int target)
{
    int min_val = 999999999;
    res[0] = 0;
    for(int i = 1; i <= target; i++)
    {
        min_val = 999999999;
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[j] <= i)
            {
                int val = res[i - arr[j]] + 1;
                if(val < min_val)
                    min_val = val;
            }
        }
        res[i] = min_val;
    }

    return res[target];
}

int main()
{
    int n, s;
    cin>>n>>s;

    vector<int> arr, res(s);
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    cout<<"Minimum number of coins are: "<<min_hit(arr, res, s)<<endl;

    return 0;
}