#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int no;
    cin>>no;

    int out = no & (no >> 1);
    cout<<out<<endl;    
    return 0;
}