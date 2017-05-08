#include <bits/stdc++.h>

using namespace std;

int get_val(char ch)
{
    if(ch == 'C')
        return 0;
    else if(ch == 'E')
        return 1;
    else
        return 2;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;

        cin>>inp;
        
        bool flag = true;
        int prev, curr;
        prev = get_val(inp[0]);

        for(int i = 1; i < inp.length(); i++)
        {
           int cur = get_val(inp[i]) ;

           if(cur < prev)
           {
                flag = false;
                break;                
           }
           else
           {
                prev = cur;
           }
        }

        if(flag)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}