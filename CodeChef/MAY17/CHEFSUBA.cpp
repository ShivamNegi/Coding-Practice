#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, p;
    cin>>n>>k>>p;

    vector<int> inpk;
    string question;

    // Taking input
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;

        inpk.push_back(no);
    }

    cin>>question;

    // duplicating the array
    for(int i = 0; i < n; i++)
    {
        inpk.push_back(inpk[i]);
    }

    // finding cum_sum
    vector<int> cum_sum, another_sum;
    for(int i = 0; i < inpk.size(); i++)
    {
        if(i == 0)
        {
            cum_sum.push_back(inpk[i]);
            another_sum.push_back(0);
        }
        else            
        {
            cum_sum.push_back(inpk[i] + cum_sum[i - 1]);
            another_sum.push_back(another_sum[i - 1] + inpk[i - 1]);
        }
    }

    // resolving queries
    int start = n, end = 2 * n;
    for(int i = 0; i < question.length(); i++)
    {
        if(question[i] == '!')
        {
            start--; end--;
            if(start == 0)
            {
                start = n;
                end = 2 * n;
            }
        }
        else if(question[i] == '?')
        {
            int val = cum_sum[start + p - 1] - another_sum[start];

            for(int j = start; j + p - 1 < end; j++)
            {
                int temp = cum_sum[j + p -1] - another_sum[j];
                if(temp > val)
                {
                    val = temp;
                }
            }
            cout<<val<<endl;
        }
    }

    return 0;
}