#include <iostream>

using namespace std;

long int getgcd(long int no1, long int no2)
{
    if(no1 % no2 == 0)
        {return no2;}
    else
    {        return(getgcd(no2, no1 % no2));    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long int no1, no2;
        cin>>no1>>no2;

        long int gcd = getgcd(no1, no2);
        long int lcm = (no1 * no2) / gcd;

        cout<<gcd<<" "<<lcm<<endl;
    }
    return 0;
}

