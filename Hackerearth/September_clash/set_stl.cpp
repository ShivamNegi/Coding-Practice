#include <iostream>
#include <set>

using namespace std;

void display(set<string> set_inp)
{
    for(set<string>::iterator i = set_inp.begin(); i != set_inp.end(); i++)
    {
        string out = *i;
        cout<<out<<"\t";
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;

    set<string> set_inp;

    for(int i = 0; i < n; i++)
    {
        string inp;
        cin>>inp;

        set_inp.insert(inp);
    }

    display(set_inp);

    return 0;
}