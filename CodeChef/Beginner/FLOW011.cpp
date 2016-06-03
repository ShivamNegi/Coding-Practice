#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        unsigned long int sal;
        cin>>sal;

        float finalsal;
        if(sal < 1500)
        {
            finalsal = sal + 0.1 * sal + 0.9 * sal;
        }
        else
        {
            finalsal = sal + 500 + 0.98 * sal;
        }
        cout<<finalsal<<endl;
    }
    return 0;
}