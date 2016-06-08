#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int m, x, y;
        cin>>m>>x>>y;

        vector<int> a;
        for(int i = 0; i < m; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
        }

        bool houses[100];
        for(int i = 0; i < 100; i++)
            houses[i] = false;

        int dist = x * y;
        for(int i = 0; i < a.size(); i++)
        {
            for(int j = a[i] - dist -1; j < a[i] + dist && j < 100; j++)
            {
                if(j < 0)
                    j = -1;
                else if(houses[j] == false)
                    houses[j] = true;
            }
        }

        int counter = 0;
        for(int i = 0; i < 100; i++)
        {
            if(houses[i] == false)
                counter++;
        }
        cout<<counter<<endl;
    }
    return 0;
}