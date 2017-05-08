#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    bitset<10> a;
    a.set();
    a[2] = 0;
    if(!a.test(2))
        cout<<a;
    return 0;
}