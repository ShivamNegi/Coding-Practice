#include <iostream>

using namespace std;

int main()
{
    int no;
    cin>>no;
    no = no << 1;
    cout<<no<<endl;
    no = no >> 2;
    cout<<no<<endl;
    no = -no;
    cout<<no<<endl;
    no = no & -no;
    cout<<no<<endl;
    return 0;
}