#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long int t;
    cin>>t;

    while(t--)
    {
        long long int n, k, e, m;
        cin>>n>>k>>e>>m;

        vector<long long int> sum;
        long long int sergey;

        for(long long int i = 0; i < n; i++)
        {
            long long int s = 0;

            for(long long int j = 0; j < e; j++)
            {
                if(i == n - 1 && j == 0)
                    j++;
                long long int no;
                cin>>no;
                s += no;
            }
            if(i != n - 1)
                sum.push_back(s);
            sergey = s;
        }

        sort(sum.begin(), sum.end());

        long long int pos = sum.size() - k;

        if(sergey > sum[pos])
            cout<<"0\n";
        else
        {
            long long int val = sum[pos] - sergey + 1;
            if(val <= m)
            {
                cout<<val<<endl;
            }
            else
                cout<<"Impossible\n";
        }
    }
    return 0;
}