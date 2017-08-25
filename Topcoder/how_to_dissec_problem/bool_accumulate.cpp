// Accumulate works on boolean array. Considering false as 0 and true as 1.
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<bool> arr;

    for(int i = 0; i < 5; i++)
    {
        int no;
        cin>>no;
        if(no <= 0)
            arr.push_back(false);
        else
            arr.push_back(true);
    }

    cout<<accumulate(arr.begin(), arr.end(), 0)<<endl;
    return 0;
}