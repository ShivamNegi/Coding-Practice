#include <bits/stdc++.h>

using namespace std;

int baseval(int base, int call, int prevval)
{
    if(base <= 1)
        {return prevval;}
    else
    {
        int val = 9 * prevval + pow(10, call);
        return(baseval(base - 1, call + 1, val));    
    }
           
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long int no, copyno;
        int base, minno = 0;
        int i;
        cin>>no;
        copyno = no;

        for(i = 0; i < 10; i++)
        {
            if(int(no / pow(10, i)) == 0)
                break;
        }

        base = i - 1;
        minno += baseval(base, 1, 1);
        cout<<minno<<endl;

        
        if(minno == 1)
            minno = 0;
        no = no / pow(10, base);

        while(base != 0)
        {
            for(i = 0; i < 10; i++)
            {
            if(int(no / pow(10, i)) == 0)
                break;
            }

            base = i - 1;
            if(baseval(base, 1, 1) != 1)
                minno += baseval(base, 1, 1);
            no = no / pow(10, base);
        }

        if(copyno % 100 < 30)
            minno += copyno % 10;
        else
            minno += copyno % 10 + 9; 
        cout<<minno<<endl;                              
    }
    
    return 0;
}