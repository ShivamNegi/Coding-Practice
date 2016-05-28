#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        vector<int> arr, index;
        int n;
        cin>>n;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
            if(no < 0)
            {            index.push_back(i);        }
        }

        for(int i = 0; i < index.size(); i++)
        {
            vector<int> temp;
            for(int j = 0; j < arr.size(); j++)
            {                temp.push_back(arr[j]);            }
            temp.erase(temp.begin() + index[i]);
            display(temp);
        }    
    }

    
    return 0;
}