#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int no;
        cin>>no;
        cout<<log(no) / log(2)<<endl;
    }

    return 0;
}