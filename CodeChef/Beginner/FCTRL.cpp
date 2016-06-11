#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int no;
        cin>>no;
        long long int counter = 0;

        while(no != 0)
        {
            counter += no / 5;
            no /= 5;
        }

        cout<<counter<<endl;
    }
    return 0;
}