#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        unsigned long int n, m, x;
        cin>>n>>m>>x;

        unsigned long int sum = 0;
        unsigned long int a[n];

        for(unsigned long int i = 0; i < n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        float currmean = float(sum) / n;
        if(currmean > x)
        {
            cout<<"1\n";
        }
        else
        {
            unsigned long int no;
            no = (x * (n + 1)) - sum;
            if(no > m)
                cout<<"Impossible\n";
            else
                cout<<no<<endl;
        }
    }

    return 0;
}