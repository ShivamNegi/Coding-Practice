#include <bits/stdc++.h>

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
    scanf(" %d", &n);

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
    int q;
    scanf(" %d", &q);

    for(int i = 0; i < q; i++)
    {
        int x, y;
        //scanf(" %d %d", &x, &y);
        cin>>x>>y;

        if(x)
        {
            for(map<string, int>::iterator it = order.begin(); it != order.end(); it++)
            {
                if(it->second == y)
                    {
                        cout<<it->first<<endl;
                        break;
                    }
            }
        }
        else
        {
            for(map<string, int>::iterator it = order.begin(); it != order.end(); it++)
            {
                if(it->second >= y)
                {
                    //printf("%s\n", it->first);
                    cout<<it->first<<endl;
                    break;
                }
            }
        }
    }

    return 0;
}