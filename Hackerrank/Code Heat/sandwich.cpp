#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int p, x;
        cin>>p>>x;
        vector<int> inp, diff;

        for(int i = 0; i < p; i++)
        {
            int no;
            cin>>no;
            inp.push_back(no);
        }

        sort(inp.begin(), inp.end());

        if(x == 1)
        {
            cout<<inp[inp.size() - 1] - inp[0]<<endl;
        }
        else
        {
            reverse(inp.begin(), inp.end());
            for(int i = 0; i < inp.size() - 1; i++)
            {
                diff.push_back(inp[i] - inp[i + 1]);
            }

            sort(diff.begin(), diff.end());
            reverse(diff.begin(), diff.end());
            vector<int> dist;

            for(int i = 0; i < x -1; i++)
            {
                dist.push_back(diff[i]);
            }

            if(x != p - 1 )
            {
                int totsum = inp[inp.size() - 1] - inp[0];
                
                int currsum = 0;
                for(int i = 0; i < dist.size(); i++)
                    currsum += dist[i];
                dist.push_back(totsum - currsum);
    
            }
            
            int max_dist = 0;

            for(int i = 0; i < dist.size(); i++)
            {
                if(dist[i] > max_dist)
                    max_dist = dist[i];
            }
            display(diff);
            display(dist);
            cout<<max_dist<<endl;
        }

    }
    return 0;
}