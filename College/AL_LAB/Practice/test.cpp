#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int lim = 1<<n;

    for(int i = 0; i < lim; i++)
    {
        for(int j = 1; j < lim;)
        {
            cout<<(i&j)<<endl;
            j = j<<1;
        }
        cout<<endl;
    }
    return 0;
}