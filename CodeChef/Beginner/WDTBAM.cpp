#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        char inp[n], out[n];

        cin>>inp;
        cin>>out;

        int same = 0;

        for(int i = 0; i < n; i++)
        {
            if(inp[i] == out[i]) 
                same++;
        }

        int val[n];

        for(int i = 0; i < n + 1; i++)
        {
            cin>>val[i];
        }

        int max_val = val[0];

        for(int i = 0; i <= same; i++)
        {
            if(val[i] > max_val)
                max_val = val[i];
        }
        cout<<max_val<<endl;
    }
    return 0;
}