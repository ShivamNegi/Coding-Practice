#include <iostream>
#include <cmath>

using namespace std;

bool isprime(int no)
{
    bool flag = true;
    for(int i = 2; i <= sqrt(no); i++)
    {
        if(no % i == 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

bool isrev(int no)
{
    int revno = 0, copyno = no;

    while(no != 0)
    {
        revno = revno * 10 + no % 10;
        no /= 10;
    }

    if(revno == copyno)
        return true;
    else
        return false;
}

int main()
{
    int no;
    cin>>no;

    for(int i = no; ; i++)
    {
        if(isprime(i))
        {
            if(isrev(i))
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
