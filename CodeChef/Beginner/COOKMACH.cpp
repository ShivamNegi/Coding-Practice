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

        int counter = 0;

        while(ini != final)
        {
            while((ini & -ini) != ini)
            {
                ini >>= 1;
                counter++;
            }
            
            
            while(ini < final)
            {
                ini <<= 1;
                counter++;
            }
            
            while(ini > final)
            {
                ini >>= 1;
                counter++;
            }

        }

        cout<<counter<<endl;        
    }
    return 0;
}