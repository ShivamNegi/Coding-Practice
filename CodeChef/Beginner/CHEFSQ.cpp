#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int size;
        cin>>size;

        int a[size];

        for(int i = 0; i < size; i++)
            cin>>a[i];

        int subsize;
        cin>>subsize;

        int b[subsize];

        for(int i = 0; i < subsize; i++)
            cin>>b[i];

        int count = 0;

        for(int i = 0; i < subsize; i++)
        {
            bool flag = false;
            for(int j = 0; j < size; j++)
            {                
                if(a[j] == b[i])
                {
                    count++;
                    flag = true;
                    break;
                }
            }
            if(!flag)
                break;
        }

        if(count == subsize)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}