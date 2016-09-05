#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    vector< string > inp;

    for(int i = 0; i < t; i++)
    {
        string input;
        cin>>input;

        inp.push_back(input);
    }

    sort(inp.begin(), inp.end());
    string prev = inp[0];
    int counter = 1;

    for(int i = 1; i < inp.size(); i++)
    {
        if(prev == inp[i])
        {
            counter++;
        }
        else
        {
            cout<<prev<<" "<<counter<<endl;
            prev = inp[i];
            counter = 1;
        }
    }

    cout<<prev<<" "<<counter<<endl;

    return 0;
}