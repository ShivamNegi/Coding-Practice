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

        int up, down;
        up = down = 0;

        for(int i = 0; i < inp.length(); i++)
        {
            if(i == 0)
            {
                if(inp[i] == 'U')       
                    up++;
                else
                    down++;
            }
            else
            {
                if(inp[i] != inp[i - 1])
                {
                    if(inp[i] == 'U')       
                        up++;
                    else
                        down++;       
                }
            }
        }

        int min = up>down?down:up;

        cout<<min<<endl;
    }
}