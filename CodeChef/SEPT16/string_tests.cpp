#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string inp;
    cin>>inp;

    inp[2] = inp[3] = '.';
    cout<<inp;    

    return 0;
}