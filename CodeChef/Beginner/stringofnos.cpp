#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string inp = "";

    for(int i = 0; i < 5; i++)
    {
        int no;
        cin>>no;

        string next = "";
        while(no != 0)
        {
            char val = (no % 10) + '0';
            next += val;
            no /= 10;
        }
        string revnext = "";

        for(int j = next.length(); j >= 0; j--)
        {
            revnext += next[j];
        }
        inp += revnext;
    }

    cout<<inp<<endl;    
    return 0;
}