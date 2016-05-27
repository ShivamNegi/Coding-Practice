#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int t;
    cin>>t;

    vector<long long int> h, l;

    for(int i = 0; i < t;i++)
    {
        long long int no1, no2;
        cin>>no1>>no2;

        h.push_back(no1);
        l.push_back(no2);
    }

    unsigned int max_val = 0;
    for(long long int i = 0; i < t; i++)
    {        
        long long int prev = i + 1;
        unsigned long long int max = h[i];
        for(long long int j = i + 1; j < t; j++)
        {
            if(h[j] >= 0)
            {
                if(l[prev] <= l[j])
                {
                    max += h[j];
                    prev = l[j];
                }
            }
        }

        if(max > max_val)
            max_val = max;
    }

    cout<<max_val<<endl;

    return 0;
}
