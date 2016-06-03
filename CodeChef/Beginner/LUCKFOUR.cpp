#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long int no;
        long int counter = 0;
        cin>>no;

        while(no != 0)
        {
            if(no % 10 == 4)
                counter ++;
            no /= 10;
        }

        cout<<counter<<endl;
    }

    return 0;
}