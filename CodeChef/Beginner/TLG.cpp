#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    int maxlead = 0, player = 0;
    int no1, no2;
    no1 = no2 = 0;

    for(int i = 0; i < t; i++)
    {
        int a, b;
        cin>>a>>b;

        no1 += a;
        no2 += b;

        if(no1 > no2 && (no1 - no2) > maxlead)
        {
            maxlead = (no1 - no2);
            player = 1;
        }
        else if(no2 > no1 && (no2 - no1) > maxlead)
        {
            maxlead = no2 - no1;
            player = 2;
        }
    }

    cout<<player<<" "<<maxlead<<endl;
    return 0;
}