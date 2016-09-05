#include <iostream>
#include <vector>

using namespace std;

int ispresent(vector<int> arr, int no)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(no == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        vector< vector< pair<int, int> > > arr(n);

        for(int i = 0; i < m; i++)
        {
            int x, y;
            cin>>x>>y;
            arr[x].push_back(make_pair(y, 1));
            arr[y].push_back(make_pair(x, 1));
        }

        int counter = 0;

        while(counter != n)
        {
            vector<int> reached;        
            int max_friends = 0, pos;

            for(int i = 0; i < arr.size(); i++)
            {
                if(max_friends < arr[i].size())
                {
                    max_friends = arr[i].size();
                    pos = i;
                }
            }

            counter = max_friends;
            reached.push_back(pos);
            for(int i = 0; i < arr[pos].size(); i++)
            {
                reached.push_back(arr[pos][i].first);
            }    

            for(int i = 0; i < arr.size(); i++)
            {
                for(int j = 0; j < arr[i].size(); j++)
                {
                    if((val = ispresent(reached, arr[i][j].first)) >= 0)
                    {
                        arr[i].erase(val);
                    }
                }
            }
        }    
    }
    return 0;
}