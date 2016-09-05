#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string one, two;
        cin>>one>>two;

        bool flag_one = true;
        int j = 0, i;

        for(i = 0; i < two.length(); i++)
        {
            bool found = false;
            for(j; j < one.length(); j++)
            {
                if(one[j] == two[i])
                    {
                        found = true;
                        j++;
                        break;
                    }
            }

            if(!found)
            {
                flag_one = false;
                break;
            }
        }

        reverse(one.begin(), one.end());

        bool flag_two = true;
        i = j = 0;

        for(i; i < two.length(); i++)
        {
            bool found = false;
            for(j; j < one.length(); j++)
            {
                if(one[j] == two[i])
                    {
                        found = true;
                        j++;
                        break;
                    }
            }

            if(!found)
            {
                flag_two = false;
                break;
            }
        }

        if(flag_two && flag_one)
            cout<<"3\n";
        else if(flag_one)
            cout<<"1\n";
        else if(flag_two)
            cout<<"2\n";
        else
            cout<<"0\n";
    }
    return 0;
}
