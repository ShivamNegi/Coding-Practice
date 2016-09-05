#include <iostream>
#include <vector>

using namespace std;

void display(vector<long long> arr)
{
    for(long long i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<endl;
    }
}

bool isdiv(long long val, long long a, long long b)
{
    val -= b;
    return val % a == 0;
}

void get(vector<long long> &series, long long a, long long b, long long l, long long r)
{
    long long lower, higher;

    for(long long i = l; i < r; i++)
    {
        if(isdiv(i, a, b))
        {
            lower = (i - b) / a;
            break;
        }
    }

    for(long long i = r; ; i++)
    {
        if(isdiv(i, a, b))
        {
            if(i == r)
            {
                series.push_back(i);
            }
            higher = (i - b) / a;
            break;
        }
    }

    for(long long i = lower; i < higher; i++)
    {
        if(i > 0)
            series.push_back(a * i + b);
    }
}

long long getcmmnumbers(vector<long long> series, long long a, long long b)
{
    long long res = 0;
    for(long long i = 0; i < series.size(); i++)
    {
        if(isdiv(series[i], a, b))
            if(series[i] - b > 0)
                res++;
    }
    return res;
}

int main()
{
    long long a1, b1, a2, b2, l, r;

    cin>>a1>>b1>>a2>>b2>>l>>r;

    vector<long long> series;    

    if(a1 > a2)
    {
        get(series, a1, b1, l, r);
        cout<<getcmmnumbers(series, a2, b2)<<endl;
    }
    else
    {
        get(series, a2, b2, l, r);
        cout<<getcmmnumbers(series, a1, b1)<<endl;
    }    

    return 0;
}