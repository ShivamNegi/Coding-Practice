#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string one, two;
        cin>>one>>two;

        int unknown, same, diff;
        unknown = same = diff = 0;

        for(int i = 0; i < one.length(); i++)
        {
            if(one[i] == '?' || two[i] == '?')
            {
                unknown++;
            }
            else
            {
                if(one[i] == two[i])
                    same++;
                else
                    diff++;
            }
        }

        cout<<diff<<" "<<diff+unknown<<endl;
    }
    return 0;
}