#include <bits/stdc++.h>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" " ;
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;

        vector<int> arr;

        for(int i = 0; i < inp.length(); i++)
        {
            arr.push_back(inp[i] - 'a');
        }

        bool flag = true;
        for(int i = 0; i < arr.size() - 1; i++)
        {
            int val = abs(arr[i] - arr[i + 1]);
            if(val == 1 || val == 25)
            {
                continue;                
            }
            else
            {
                flag = false;
                break;
            }
        }

        //display(arr);
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}