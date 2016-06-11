#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int year;
        cin>>year;

        int day_2017 = 0, thatday, extra, thatyear = 2017;

        if(year - thatyear > 0)
        {
            extra = (year - thatyear) / 4;
            thatday = day_2017 + (year - thatyear) + extra;
        }
        else if(year - thatyear < 0)
        {
            extra = abs(year - thatyear + 1) / 4 + 1;
            thatday = day_2017 + 6 * abs(year - thatyear) + 6 * extra;
        }
        else
        {
            thatday = day_2017;
        }

        if(thatday % 7 == 0)
        {
            cout<<"sunday\n";
        }
        else if(thatday % 7 == 1)
        {
            cout<<"monday\n";
        }
        else if(thatday % 7 == 2)
        {
            cout<<"tuesday\n";
        }
        else if(thatday % 7 == 3)
        {
            cout<<"wednesday\n";
        }
        else if(thatday % 7 == 4)
        {
            cout<<"thursday\n";
        }
        else if(thatday % 7 == 5)
        {
            cout<<"friday\n";
        }
        else
        {
            cout<<"saturday\n";
        }
    }
    return 0;
}