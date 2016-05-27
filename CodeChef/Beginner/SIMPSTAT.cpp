#include<iostream>
#include<vector>
#include<algorithm>
#include<stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        vector<int> arr;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        sort(arr.begin(), arr.end());

        float sum = 0;

        for(int i = k; i < n - k; i++)
        {
            sum += arr[i];
        }

        float avg = float(sum) / (n - 2 * k);

        printf("%0.6f\n", avg);
    }

    return 0;
}