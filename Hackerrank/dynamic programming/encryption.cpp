#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string inp;
    char a;

    inp = "";
    cin>>a;

    while(a != '\n')
    {
        inp += a;
        cin>>a;
    }

    string no_space_inp = "";

    for(int i = 0; i < inp.length(); i++)
    {
        no_space_inp += inp[i];
    }

    int lower = sqrt(no_space_inp.length());
    int higher = sqrt(no_space_inp.length()) + 1;

    int reqarea = no_space_inp.length();
    int closer, closer1;
    closer = lower;
    closer1 = lower + 1;

    if(closer1 * higher - reqarea > closer * higher - reqarea)
    {
        int pos = 0;
        for(int i = 0; i < closer; i++)
        {
            for(int j = 0; j < higher; j++)
            {
                cout<<no_space_inp[pos++];
            }
            cout<<endl;
        }
    }
    else
    {
        int pos = 0;
        for(int i = 0; i < closer1; i++)
        {
            for(int j = 0; j < higher; j++)
            {
                cout<<no_space_inp[pos++];
            }
            cout<<endl;
        }

    }
    return 0;
}