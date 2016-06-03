#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int ini, final;
        cin>>ini>>final;

        if(ini > final)
        {
            int temp = ini;
            ini = final;
            final = temp;
        }

        if(log2(ini) - int(log2(ini)) == 0)        
        {cout<<log2(final) - log2(ini)<<endl;}
        else
        {
            cout<<log2(final) + ceil(log2(ini)) - 1<<endl;
        }
    }
    return 0;
}