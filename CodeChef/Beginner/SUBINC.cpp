#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;

        long long int a[n];
        long long subcount = n;
        long long int counter = 0;

        for(int i = 0; i < n; i ++)
        {
            cin>>a[i];
            if(i == 0)
                {continue;}
            else if(a[i] >= a[i - 1])
                {counter++;}
            else if(counter > 0)
            {
                subcount += ((counter * (counter + 1)) / 2);
                counter = 0;
            }
        }

        if(counter != 0)
        {subcount += ((counter * (counter + 1)) / 2);}

        // cout<<subcount<<endl; is worng!
        printf("%lld\n",subcount);
    }

    return 0;
}