#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp1, inp = "";
        cin>>inp1;

        for(int i = 0; i < inp1.length(); i++)
        {
            if(inp1[i] != '=')
                inp += inp1[i];
        }

        int gr, ls, max;
        char prev, cur;

        gr = ls = max = 0;
        prev = cur = inp[0];        

        if(prev == '<')
            gr++;
        else if(prev == '>')
            ls++;

        for(int i = 1; i < inp.length(); i++)
        {
            prev = cur;
            cur = inp[i];
            
            if(cur == '<' && prev == '>')
            {
                int val;
                val = gr > ls? gr + 1: ls + 1;
                if(val > max)
                    max = val;
                gr = ls = 0;
            }

            if(cur == '<')
                gr++;
            else
                ls++;
        }

        int val;
        val = gr > ls? gr + 1: ls + 1;
        if(val > max)
            max = val;

        cout<<max<<endl;
    }
    return 0;
}