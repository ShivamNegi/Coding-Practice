#include<iostream>

using namespace std;

int main()
{
    string inp;

    cin>>inp;

    int found = inp.find_first_of("s", 2, inp.length());
    cout<<found<<endl;
    inp.erase(found, 1);
    //inp = inp.substr(found + 1, inp.length());
    cout<<inp<<endl;

    return 0;
}