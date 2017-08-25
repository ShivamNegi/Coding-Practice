#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    string buf;
    getline(cin, buf);
    while(t--)
    {
        string inp;
        getline(cin, inp);

        int spaces = 0;
        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i] == ' ')
                spaces++;            
        }

        string out = "";
        int counter = 0, iter = 0;
        while(spaces)
        {
            if(counter == 0)
            {
                out += toupper(inp[iter]);
                out += '.';
                out = out + ' ';
                counter++;
            }
            if(inp[iter] == ' ')
            {
                spaces--;
                counter = 0;
            }
            iter++;
        }

        out += toupper(inp[iter++]);
        while(iter < inp.length())
            out += tolower(inp[iter++]);

        cout<<out<<endl;
    }
    return 0;
}