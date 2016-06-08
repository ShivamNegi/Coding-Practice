#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;

        int tracked[n], ignored[n];

        for(int i = 0; i < n; i++)
            {
                tracked[i] = 0;
                ignored[i] = 0;
            }

        int inpm[m], inpk[k];
        for(int i = 0; i < m; i++)
            {
                cin>>inpm[i];   
                ignored[inpm[i] - 1]++;
            }
        for(int i = 0; i < k; i++)
            {
                cin>>inpk[i];
                tracked[inpk[i] - 1]++;
            }

        int counta, countb;
        counta = countb = 0;

        for(int i = 0; i < n; i++)
        {
            if(tracked[i] == 1 && ignored[i] == 1)
                counta++;
            else if(tracked[i] == 0 && ignored[i] == 0)
                countb++;
        }

        cout<<counta<<" "<<countb<<endl;
    }
    return 0;
}

