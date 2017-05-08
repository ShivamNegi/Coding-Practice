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

        int arr[n + 1];

        fill(arr, arr + n + 1, 1);
        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            if(arr[no] != 0)
                arr[no] = 0;
        }

        cout<<accumulate(arr, arr + n + 1, 0)<<endl;
    }
    return 0;
}