#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int year;
        cin>>year;

        int day_2016 = 5, thatday, extra;

        if(year - 2016 > 0)
        {
            extra = (year - 2016) / 4 + 1;
            thatday = day_2016 + (year - 2016) + extra;
        }
        else 
        {
            
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