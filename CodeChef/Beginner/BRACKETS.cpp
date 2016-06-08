#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;

        int bal = 0, max_bal = 0;

        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i] == '(')
                bal++;
            else
                bal--;
            if(max_bal < bal)
                max_bal = bal;
        }

        string out, start, end;
        start = end = "";

        for(int i = 0; i < max_bal; i++)
        {
            start += '(';
            end += ')';
        }

        out = start + end;

        cout<<out<<endl;
    }
    return 0;
}