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

        int reach[n][n];

        for(int i = 0; i < n; i++)
        {
            string inp;
            cin>>inp;

            for(int j = 0; j < n; j++)
            {
                if(inp[j] == '1')
                    {                        
                        reach[i][j] = 1;
                    }
                else
                    reach[i][j] = 0;
            }
        }

        //closure

        int V = n;
        for (int k = 0; k < V; k++)
            {
                for (int i = 0; i < V; i++)
                {
                    for (int j = 0; j < V; j++)
                    {
                        reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
                    }
                }
            }

        for(int i = 0; i < V; i++)
        {
            for(int j = 0; j < V; j++)
                cout<<reach[i][j]<<" ";
            cout<<endl;
        }
        
    }
    return 0;
}