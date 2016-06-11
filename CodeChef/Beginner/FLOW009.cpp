#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int qty, price;
        cin>>qty>>price;

        double total;

        if(qty > 1000)
        {
            total = qty * price * 0.9;
        }
        else
            total = qty * price;

        cout<<fixed<<setprecision(6)<<total<<endl;
    }
    return 0;
}