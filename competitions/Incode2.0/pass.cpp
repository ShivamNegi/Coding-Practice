#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        cin>>inp;    

        bool good, strong, goodupper, goodnum;
        good = goodupper = goodnum = false;

        if(inp.length() >= 8)
        {
            good = true;
        }
        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i].isupper())
            {
                goodupper = true;
            }
            if(inp[i].isnum())
                goodnum = true;
        }

        if(good && goodnum && goodupper)
            cout<<"strong\n";
        else if(good || goodnum || goodupper)
            cout<<"good\n";
        else
            cout<<"weak\n";
    }
    

    return 0;
}