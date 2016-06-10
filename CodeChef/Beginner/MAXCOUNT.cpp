#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int a[10000];

        for(int i = 0; i < 10000; i++)
            a[i] = 0;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            a[no - 1]++;
        }

        int pos = 0, max_count = a[0];

        for(int i = 0; i < 10000; i++)
        {
            if(a[i] > max_count)
            {
                max_count = a[i];
                pos = i;
            }
        }

        cout<<pos + 1<<" "<<a[pos]<<endl;
    }
    return 0;
}