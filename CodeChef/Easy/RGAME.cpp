#include <iostream>
#include <vector>
#include <algorithm>
#define MOD (1000000000 + 7)

using namespace std;

void display(vector<long> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}


long res(vector<long> arr, vector<long> out, int pointer, int length, long mul)
{
    long val1, val2;
    if(length == pointer)
        {
            display(out);
            return mul;
        }
    else
        {
            long front_mul, back_mul;
            front_mul = (mul + (out[0] * arr[pointer]) % MOD) % MOD;
            back_mul = (mul + (out[out.size() - 1] * arr[pointer]) % MOD) % MOD;

            out.push_back(arr[pointer]);
            val1 = res(arr, out, pointer + 1, length, back_mul);

            out.pop_back();
            out.insert(out.begin(), arr[pointer]);
            val2 = res(arr, out, pointer + 1, length, front_mul);
        }
    long res = (val1 + val2) % MOD;
    return res;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        n++;
        vector<long> arr;

        for(int i = 0; i < n; i++)        
        {
            long no;
            cin>>no;
            arr.push_back(no);
        }

        vector<long> out;
        out.push_back(arr[0]);

        cout<<res(arr, out, 1, n, 0)<<endl;
    }
    return 0;
}