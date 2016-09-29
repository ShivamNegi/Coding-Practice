#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

bool clash(vector<int> positions, int val, int k)
{
    for(int i = 0; i < positions.size(); i++)
    {
        if(val == positions[i] || val + k + 1 == positions[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a;
        vector<int> positions;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
            positions.push_back(i);
        }

        int k;
        cin>>k;

        vector<int> cum_sum(n);
        for(int i = 0; i + k + 1 < n; i++)
        {
            cum_sum[i] = a[i] + a[i + k + 1];
        }


        for(int i = 0; i < cum_sum.size(); i++)
        {
            for(int j = i + 1; j < cum_sum.size(); j++)
            {
                if(cum_sum[i] < cum_sum[j])
                {
                    int temp = cum_sum[i];
                    cum_sum[i] = cum_sum[j];
                    cum_sum[j] = temp;

                    temp = positions[i];
                    positions[i] =  positions[j];
                    positions[j] = temp;
                }
            }
        }

        //display(cum_sum);
        //display(positions);
        long long res = 0;
        int counter = 0;
        vector<int> included;

        for(int i = 0; i < cum_sum.size(); i++)
        {
            if(cum_sum[i] == 0)
                break;
            else
                if(clash(included, positions[i], k))
                {
                    res += cum_sum[i];
                    included.push_back(positions[i]);
                    included.push_back(positions[i] + k + 1);
                }
        }

        display(included);
        cout<<res<<endl;
    }
    return 0;
}