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
            {cin>>a[i];}

        int subsize;
        cin>>subsize;

        int b[subsize];

        for(int i = 0; i < subsize; i++)
            {cin>>b[i];}

        bool flag;

        for(int i = 0; i <= size - subsize; i++)
        {
            flag = true;
            for(int j = 0; j < subsize; j++)
            {
                if(a[i + j] != b[j])
                {
                    flag = false;
                    break;
                }
            }            
            if(flag)
                break;
        }
        if(flag)
            {cout<<"Yes\n";}
        else
            {cout<<"No\n";}
    }
    return 0;
}