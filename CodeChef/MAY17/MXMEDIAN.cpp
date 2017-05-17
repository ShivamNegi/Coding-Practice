#include <bits/stdc++.h>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> inp;
        for(int i = 0; i < 2 * n; i++)
        {
            int no;
            cin>>no;
            inp.push_back(no);
        }

        sort(inp.begin(), inp.end());

        vector<int> out;
        int val;
        for(int i = 0; i < n; i++)
        {
            out.push_back(inp[i]);
            out.push_back(inp[i + n]);

            if(i == n / 2)
                val = inp[i + n];
        }

        cout<<val<<endl;
        display(out);
    }
    return 0;
}