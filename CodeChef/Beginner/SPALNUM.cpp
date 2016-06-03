#include <iostream>

using namespace std;

int revno(unsigned long int no)
{
    unsigned long int rno = 0;
    while(no != 0)
    {
        rno = rno * 10 + no % 10;
        no /= 10;
    }
    return rno;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        unsigned int l, r;
        cin>>l>>r;
        unsigned long int sum = 0;
        
        for(unsigned long int i = l; i <=r; i++)
        {
            if(i == revno(i))
                sum += i;
        }

        cout<<sum<<endl;
    }
    return 0;
}