#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;

        cin>>n>>k;

        string inp[n], phrase[k];

        for(int i = 0; i < n; i++)
            cin>>inp[i];

        for(int i = 0; i < k; i++)
        {
            int l;
            cin>>l;

            string get;
            phrase[i] = "";

            for(int j = 0; j < l; j++)
            {
                cin>>get;
                phrase[i] = phrase[i] + " " + get;
            }
        }

        for(int i = 0; i < n; i++)
        {
            bool flag = false;

            for(int j = 0; j < k; j++)
            {
                if(phrase[j].find(inp[i]) != -1)
                    {
                        flag = true;
                        break;
                    }
            }

            if(flag)
                {cout<<"YES";}
            else
                {cout<<"NO";}
            if(i != n - 1)
                cout<<" ";            
        }
        cout<<endl;
    }
    return 0;
}
