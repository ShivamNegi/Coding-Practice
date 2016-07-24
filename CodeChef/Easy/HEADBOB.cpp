#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        string inp;
        cin>>inp;

        bool no_yes = true, no_indi_yes = true;

        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i] == 'I')
            {
                no_indi_yes = false;
                break;
            }
            else if(inp[i] == 'Y')
            {
                no_yes = false;
                break;
            }
        }

        if(!no_yes)
        {
            cout<<"NON INDIAN\n";
        }
        else if(!no_indi_yes)
            cout<<"INDIAN\n";
        else
            cout<<"NOT SURE\n";
    }
    return 0;
}
