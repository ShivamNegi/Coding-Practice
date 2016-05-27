#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp;
        int n;
        
        cin>>inp;
        cin>>n;

        string setinp;

        for(int i = 0; i < inp.length(); i++)
        {
            bool flag = true;
            for(int j = 0; j < setinp.length(); j++)
            {
                if(inp[i] == setinp[j])
                {
                    flag = false;
                    break;
                }
            }

            if(flag)
            {
                setinp = setinp + inp[i];
            }
        }

        cout<<setinp;

        
        for(int i = 0 ; i < setinp.length(); i++)
        {
            int count = 0;
            for(int j = 0; j < inp.length(); j++)
            {
                if(inp[j] == setinp[i])
                    count ++;
                if(count > n)
                {
                    
                }
            }
        }
    }
    return 0;
}
