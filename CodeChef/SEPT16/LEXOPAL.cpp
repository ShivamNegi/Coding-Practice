#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;

        int l = inp.length();
        bool flag = true;

        for(int i = 0; i < l / 2; i++)
        {           
            int k = l - i - 1;
        
            if(inp[i] == '.' && inp[k] == '.')
                inp[i] = inp[k] = 'a';
            else if(inp[i] == '.')
                inp[i] = inp[k];
            else if(inp[k] == '.')
                inp[k] = inp[i];
            else if(inp[i] != inp[k])
                {
                    flag = false;
                    break;
                }
        }
        if(inp[l / 2] == '.')
            inp[l / 2] = 'a';
        if(!flag)
            cout<<"-1\n";
        else
            cout<<inp<<endl;
    }
    return 0;
}