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

        int min = 100;

        string inp;

        for(int i = 0; i < n; i++)
        {
            cin>>inp;

            int counta = 0, m = inp.length();
            for(int i = 0; i < m; i++)
            {
                if(inp[i] == 'a')
                    counta++;
            }

            if(counta > m / 2)
            {
                if(min > (m - counta))
                {
                    min = m - counta;
                }
            }
            else
                if(min > counta)
                    min = counta;
        }  
        cout<<min<<endl; 
    }

    return 0;
}