#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    string inp;
    int counter[t + 1];
    counter[0] = 0;

    cin>>inp;
    for(int i = 0; i < t; i++)
    {
        int val = 0;
        if(inp[i] == 'U')
            val = 1;
        else
            val = -1;

        counter[i + 1] = counter[i] + val;
    }

    int valley_count = 0;
    bool valley_on = false;
    for(int i = 0; i < t + 1; i++)
    {
        if(counter[i] == 0)
        {
            if(!valley_on)    
            {
                if(counter[i + 1] < 0)
                    valley_on = true;
            }
            else
            {
                valley_count++;
                valley_on = false;
                i--;
            }    
        }
    }

    cout<<valley_count<<endl;
    return 0;
}