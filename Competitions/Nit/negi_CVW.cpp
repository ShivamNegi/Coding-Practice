#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
 
void display(vector<long long> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
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

        for(int i = 0; i < n; i++)
        {
            long long val = a[i];
            long long no_a = count(out.begin(), out.end(), a[i]);
            long long no_b = count(out.begin(), out.end(), b[i]);
            //cout<<no_a<<"\t"<<no_b<<"\n";
            if(!no_b && !no_a)
                val = min(a[i], b[i]);
            else if(!no_a)
                val = a[i];
            else if(!no_b)
                val = b[i];
            else
            {
                flag = false;
                break;
            }
            if(val == pow(10, 6))
            {
                flag = false;
                break;
            }
            out.push_back(val);
            /*display(out);*/
        }
 
        if(flag)
            display(out);
        else
            cout<<"CAPTAIN AMERICA EVADES\n";
    }
    return 0;
} 