#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        string inp;
        cin>>inp;

        
        if(k > 1)
        {            
            sort(inp.begin(), inp.end());
            cout<<inp[0]<<endl;
        }
        else
        {
            string c_inp = inp;
            sort(inp.begin(), inp.end());

            if(inp[0] == c_inp[0])
                cout<<inp[0]<<endl;
            else
            {
                string out = "";

                for(int i = inp.length(); i >= 0; i--)
                {
                    out = c_inp[i] + out;
                    if(inp[0] == c_inp[i])
                    {                        
                        break;
                    }
                }
                cout<<out<<endl;
            }                
        }
    }
    return 0;
}