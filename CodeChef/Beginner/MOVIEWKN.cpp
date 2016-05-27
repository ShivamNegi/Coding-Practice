#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> outarr)
{
    for(int i = 0; i < outarr.size(); i++)
    {
        cout<<outarr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> length, rating, res;

        // taking inputs of length and rating
        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            length.push_back(no);
        }

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            rating.push_back(no);
        }

        // index of maximum value of l * r is stored in res
        int max = 0;
        for(int i = 0; i < n; i++)
        {
            if(length[i] * rating[i] > max)
            {
                res.clear();
                max = length[i] * rating[i];
                res.push_back(i + 1);
            }
            else if(length[i] * rating[i] == max)
            {
                res.push_back(i + 1);
            }
        }

        // outputting the index
        if(res.size() == 1)
        {
            cout<<res[0]<<endl;
        }
        // if there are more than one
        else
        {
            vector<int> finalres;
            int max_rating = rating[res[0] - 1];
            
            for(int i = 0; i < res.size(); i++)
            {
                int j = res[i] - 1;
                if(max_rating < rating[j])
                {
                    finalres.clear();
                    max_rating = rating[j];
                    finalres.push_back(j + 1);
                }
                else if(max_rating == rating[j])
                {
                    finalres.push_back(j + 1);
                }
            }
            cout<<finalres[0]<<endl;            
        }
    }
    
    return 0;
}