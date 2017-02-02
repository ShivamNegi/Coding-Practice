#include <bits/stdc++.h>

using namespace std;

void display(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int size, h;
        cin>>size>>h;

        vector< pair<int, int> > val;
        for(int i = 0; i < size; i++)
        {
            int no1, no2;
            cin>>no1>>no2;
            val.push_back(make_pair(no1, no2));
        }

        int empty[size] = {0};
        for(int i = 0; i < size; i++)
        {
            for(int j = val[i].first; j <= val[i].second; j++)
                empty[j]++;
        }

        int cum_sum[size], sum = 0;
        cum_sum[0] = empty[0];
        for(int i = 1; i < size; i++)
            cum_sum[i] = cum_sum[i - 1] + empty[i];

        for(int i = 0; i < size - h; i++)
        {
            int s;
            s = cum_sum[i + h] - cum_sum[i];
            if(s > sum)
                sum = s;
        }

        cout<<size * h - sum<<endl;
    }

    return 0;
}