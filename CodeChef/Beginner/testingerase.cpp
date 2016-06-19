#include <iostream>

using namespace std;

int main()
{
    string inp;
    cin>>inp;

    int pos;
    pos = inp.find_first_of('h');
    cout<<pos<<endl;
    inp = inp.substr(pos, inp.length())  ;
    cout<<inp<<endl;
    return 0;
}