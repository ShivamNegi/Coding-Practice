#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int max = 0, pos;

        for(int i = 2; i <= k; i++)
        {
            if((n % i) > max)
            {
                max = n % i;
                pos = i;
            }           
            
        }
        
        cout<<n - pos * (n / pos)<<endl;
    }
    return 0;
}