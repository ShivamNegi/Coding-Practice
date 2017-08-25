#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, d;
        cin>>n>>d;

        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];

        ll mean = accumulate(arr.begin(), arr.end(), 0) / arr.size();
        bool flag = true;
        int output = 0;
        for(int i = 0; i < d; i++)
        {
            int pos = i;
            int counter = 0, res = 0, diff = 0;
            while(pos < n)
            {  
                counter++;
                res = res + arr[pos];
                diff = diff + abs(arr[pos] - mean);
                pos += d;
            }
            if(res / counter != mean)
            {
                flag = false;
                break;
            }
            else
            {
                output = output + diff / 2;
            }
        }

        if(flag)
            cout<<output<<endl;
        else
            cout<<"-1\n";
    }
    return 0;
}