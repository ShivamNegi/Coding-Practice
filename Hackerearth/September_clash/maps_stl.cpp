#include <iostream>
#include <map>

using namespace std;

void display(map<string, int> out)
{
    for(map<string, int>::iterator i = out.begin(); i != out.end(); i++)
    {
        cout<<i->first<<"\t"<<i->second;
        cout<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    map<string, int> order;

    for(int i = 0; i < n; i++)
    {
        string inp;
        cin>>inp;

        if(order.find(inp) != order.end())
            order[inp]++;
        else
            order[inp] = 1;
    }

    display(order);
    return 0;
}