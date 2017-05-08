#include <bits/stdc++.h>

using namespace std;

void display(vector<long long> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--)
    {
        long long n, k;
        cin>>n>>k;

        vector<long long> a(n), b(n);

        fill(a.begin(), a.end(), pow(10, 6));
        fill(b.begin(), b.end(), pow(10, 6));

        for(int i = 0; i < n - k; i++)
        {
            a[i + k] = i + 1;
            b[n - k - i - 1] = n - i;
        }

        /*display(a);
        display(b);*/
        vector<long long> out;
        bool flag = true;

        vector<long long> one;
        for(int i = 0; i < k; i++)
        {
            one.push_back(min(a[i], b[i]));            
        }
        for(int i = 0; i < k; i++)
        {
            int val = count(one.begin(), one.end(), b[n - i]);
            if(val)
            {
                flag = false;
                break;
            }
        }

        if(!flag)
            cout<<"CAPTAIN AMERICA EVADES\n";
        else
        {
            bool ha_flag = false;
            for(int i = 0; i < n; i++)
            {
                long long val = min(a[i], b[i]);
                if(val == pow(10, 6))
                {
                    ha_flag = true;
                    break;
                }
                a[find(a.begin(), a.end())]
                out.push_back(val);
            }
            if(ha_flag)
                cout<<"CAPTAIN AMERICA EVADES\n";
            else
                display(out);
        }
    }
    return 0;
}