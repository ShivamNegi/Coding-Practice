#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int no;
        cin>>no;

        long int mul = -1;
        int lower = int(sqrt(no));
        for(int i = no / 2; i >= lower; i--)
        {
            // will optimize more if doesn't work
            for(int j = i - 1; j >= lower; j--)
            {
                int third = no - i - j;

                if(pow(third, 2) + pow(j , 2) == pow(i, 2))
                {
                    long int val = i * j * third;
                    if(mul < val)
                        mul = val;
                }
            }
        }
        cout<<mul<<endl;
    }
    return 0;
}