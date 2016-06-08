#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string a, b;
        cin>>a;
        cin>>b;

        string out = "";       

        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] == b[i])
                {
                    if(a[i] == 'W')
                        out += 'B';
                    else
                        out += 'W';
                }
            else
                out += 'B';
        }

        cout<<out<<endl;
    }
    return 0;
}