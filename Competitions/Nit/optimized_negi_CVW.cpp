#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

#define MAX_SIZE pow(10, 6)
 
using namespace std;

void display_bitset(bitset<100000> check, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout<<check[i];
    }
    cout<<endl;
}
 
void display(vector<long long> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

bool checking_bits(bitset<100000> check, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(check[i] == 0)
            return false;
    }
    return true;
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
 
        fill(a.begin(), a.end(), MAX_SIZE);
        fill(b.begin(), b.end(), MAX_SIZE);
 
        for(int i = 0; i < n - k; i++)
        {
            a[i + k] = i + 1;
            b[n - k - i - 1] = n - i;
        }
 
        /*display(a);
        display(b);*/
        vector<long long> out;
        bitset<100000> check;
        check.reset();
        bool flag = true;

        for(int i = 0; i < n; i++)
        {
            long long val;

            if(a[i] == MAX_SIZE)
            {
                if(b[i] == MAX_SIZE)
                {
                    flag = false;
                    break;
                }
                else
                {
                    if(check.test(b[i] - 1))
                    {
                        flag = false;
                        break;
                    }
                    val = b[i];
                }
            }
            else
            {
                if(b[i] == MAX_SIZE)
                {
                    if(check.test(a[i] - 1))
                    {
                        flag = false;
                        break;
                    }
                    val = a[i];
                }                
                else
                {
                    if( check.test(b[i] - 1) && check.test(a[i] - 1) )
                    {
                        flag = false;
                        break;
                    }
                    if( !check.test(b[i] - 1) && !check.test(a[i] - 1) )
                    {
                        val = min(a[i], b[i]);
                    }
                    else if(!check.test(b[i] - 1))
                        val = b[i];
                    else
                        val = a[i];
                }                 
            }

            check.set(val - 1);
            out.push_back(val);
        }

        if(flag && checking_bits(check, n))
            display(out);
        else
            cout<<"CAPTAIN AMERICA EVADES\n";
        /*display_bitset(check, n);
        display(out);*/
    }

    return 0;
}   