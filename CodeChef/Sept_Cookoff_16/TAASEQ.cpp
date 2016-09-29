#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isap(vector<long long> a)
{
    long long prev = a[0];
    for(long long i = 1; i < a.size(); i++)
    {
        if(prev != a[i])
            return false;
    }
    return true;
}

long long recur_remove(vector<long long> a)
{
    for(long long i = 0; i < a.size(); i++)
    {
        vector<long long> new_a;
        for(long long j = 0; j < a.size(); j++)
        {
            if(j != 1)
                new_a.push_back(a[j]);
        }   
        if(isap(new_a))
            return a[i];        
    }
    return -1;
}

void display(vector< pair<long long, long long> > a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i].first<<"\t"<<a[i].second<<endl;
    }
}

void display_arr(vector<long long> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    long long t;
    cin>>t;

    while (t--)
    {
        long long n;
        cin>>n;

        vector<long long> a;

        for(long long i = 0; i < n; i++)
        {
            long long no;
            cin>>no;
            a.push_back(no);
        }

        if(n > 5)
        {
            vector<long long> cum;
            long long max_cum;
            bool flag = false;

            for(long long i = 0; i < n - 1; i++)
            {
                cum.push_back(a[i + 1] - a[i]);
            }

            vector< pair<long long, long long> > vals;

            for(long long i = 0; i < cum.size(); i++)
            {
                /*cout<<"size of pair is:"<<vals.size()<<endl;
                display(vals);*/
                bool flag = false;
                long long j;
                if(vals.size() > 2)
                {
                    flag = true;
                    break;
                }
                else
                {
                    if(vals[0].first > 2)
                    {
                        max_cum = vals[0].first;
                        break;
                    }
                    else if(vals[1].first > 2)
                    {
                        max_cum = vals[1].first;
                        break;
                    }
                }
                for(j = 0; j < vals.size(); j++)
                {
                    if(vals[j].first == cum[i])
                    {
                        flag = true;
                        break;
                    }
                }

                if(flag)
                {
                    vals[j].second++;
                }
                else
                    {
                        // cout<<"new no"<<endl;
                        vals.push_back(make_pair(cum[i], 1));
                    }
            }

            if(flag)
                cout<<"-1\n";
            else
            {                
                long long i;
                for(i = 0; i < cum.size(); i++)
                {
                    if(cum[i] != max_cum)
                    {
                        break;
                    }
                }

                cout<<a[i + 1]<<endl;

                //display(vals);
                //display_arr(cum);
            }
        }
        else
        {
            cout<<recur_remove(a)<<endl;
        }   
    }
    return 0;
}