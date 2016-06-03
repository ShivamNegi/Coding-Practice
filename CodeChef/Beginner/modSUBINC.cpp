#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;

        unsigned long int a[n];
        vector<long int> arr;

        for(int i = 0; i < n; i ++)
        {
            cin>>a[i];
            if(i == 0)
                {arr.push_back(1);}
            else if(a[i] >= a[i - 1])
                {arr.push_back(arr[i - 1] + 1);}
            else
                {arr.push_back(1);}
        }

        //cout<<accumulate(arr.begin(),arr.end(), 0)<<endl; is wrong!
        printf("%lld\n",accumulate(arr.begin(),arr.end(), 0));
    }

    return 0;
}