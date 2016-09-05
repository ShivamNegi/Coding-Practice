#include <iostream>
#include <string>

using namespace std;

int main()
{
    string inp;
    cin>>inp;

    int x, y;
    x = inp[0] - 'a';
    y = inp[1] - '0';

    x++;
    int res = 0;
    if(x + 1 < 9 && y + 1 < 9)
        res ++;
    if(y + 1 < 9)
        res ++;
    if(x + 1 < 9)
        res ++;
    if(x - 1 > 0 && y - 1 > 0)
        res ++;
    if(x - 1 > 0)
        res ++;
    if(y - 1 > 0)
        res ++;
    if(x + 1 < 9 && y - 1 > 0)
        res ++;
    if(x - 1 > 0 && y + 1 < 9)
        res ++;
    cout<<res<<endl;
    return 0;
}