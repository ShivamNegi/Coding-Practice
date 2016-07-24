#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, d;
        cin>>n>>d;

        string inpstr, outstr;
        cin>>inpstr>>outstr;

        if(inpstr.length() != outstr.length())
        {
            cout<<"No\n";
            continue;
        }

        bool flag = true;

        
            int inpcount[26][d], outcount[26][d];

            for(int i = 0; i < 26; i++)
            {
                for(int j = 0; j < d; j++)
                {
                    inpcount[i][j] = outcount[i][j] = 0;
                }
            }

            

            for(int j = 0; j < inpstr.length(); j++)
            {
                inpcount[int(inpstr[j]) - 97][j % d]++;
                outcount[int(outstr[j]) - 97][j % d]++;
            }

            bool fflag = true;
            for(int i = 0; i < 26; i++)
            {
                for(int j = 0; j < d; j++)
                {
                    if(inpcount[i][j] != outcount[i][j])
                    {
                        fflag = false;
                        break;
                    }
                }
                if(!fflag)
                {
                    flag = false;
                    break;
                }
            }
                
        if(flag)
        {
            cout<<"Yes\n";
        }
        else
            cout<<"No\n";
    }
    return 0;
}