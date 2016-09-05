#include <bits/stdc++.h>

using namespace std;

bool isprime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int LeastPrimeDivisor(int no)
{
    if(isprime(no))
        return no;
    else
    {
        for(int i = 2; i <= sqrt(no); i++)
        {
            if(no % i == 0 && isprime(i))
                return i;
        }
    }
}

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void type0(vector<int>& a, int l, int r)
{
    for(int i = l - 1; i < r; i++)
    {
        a[i] /= LeastPrimeDivisor(a[i]);
    }
}

int type1(vector<int> a, int l, int r)
{
    int res = 1;
    for(int i = l - 1; i < r; i++)
    {
        int val = LeastPrimeDivisor(a[i]);
        if(res < val)
            res = val;
    }
    return res;
}

int main()
{
    std::ios_base::sync_with_stdio(false); 
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        vector<int> arr;

        cin>>n>>m;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        // optimizing
        vector <int> tv;
        vector <int> lv; 
        vector <int> rv;
        for(int i = 0; i < m ; i++)
        {
            int t, l, r;
            cin>>t>>l>>r;
            tv.push_back(t);
            lv.push_back(l);
            rv.push_back(r);
        }

        for(int i = 0; i < m; i++)
        {
            
            if(tv[i] == 0)
                {   
                    type0(arr, l, r);
                }
            else
                {                    
                    cout<<type1(arr, l, r)<<" ";            
                }
        }
        cout<<endl;
    }
    return 0;
}