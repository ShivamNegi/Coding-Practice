#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        char a;
        cin>>a;

        a = tolower(a);

        if(a == 'b')
            cout<<"BattleShip\n";
        else if(a == 'c')
            cout<<"Cruiser\n";
        else if(a == 'd')
            cout<<"Destroyer\n";
        else if(a == 'f')
            cout<<"Frigate\n";
    }
    return 0;
}