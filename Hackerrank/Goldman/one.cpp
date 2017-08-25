#include <bits/stdc++.h>

using namespace std;

float calcfee(vector<float> & arr, float k, float x)
{
    float res = 0;
    for(float i = 0; i < arr.size(); i++)
    {
        res = res + max(k, x * arr[i] / 100);
    }

    return res;
}

int main()
{
    float t;
    cin>>t;

    while(t--)
    {
        float n, k, x, d;
        cin>>n>>k>>x>>d;

        vector<float> arr;
        for(float i = 0; i < n; i++)
        {
            float no;
            cin>>no;
            arr.push_back(no);
        }

        if(calcfee(arr, k, x) <= d)
            cout<<"fee\n";
        else
            cout<<"upfront\n";
    }
    return 0;
}