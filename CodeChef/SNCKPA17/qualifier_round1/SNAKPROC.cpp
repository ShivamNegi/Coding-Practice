#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int len;
        string inp;
        cin>>len>>inp;

        int val = 0;
        bool flag = true;

        for(int i = 0; i < len; i++)
        {
            if(inp[i] == 'H')
            {
                val++;
                if(val > 1)
                {
                    flag = false;
                    break;
                }
            }
            else if(inp[i] == 'T')
            {
                val--;
                if(val < 0)
                {
                    flag = false;
                    break;
                }
            }
        }

        if(flag && val == 0)
            cout<<"Valid\n";
        else
            cout<<"Invalid\n";
    }
    return 0;
}