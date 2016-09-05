#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

bool check(vector<int> a, int l, int r)
{
    vector<int> b;

    for(int i = l; i <= r; i++)
        b.push_back(a[i]);

    sort(b.begin(), b.end());
    // display(b);
    for(int i = 0; i < b.size() - 1; i++)
    {
        if(b[i] == b[i + 1])
            return false;
    }
    return true;
}

int main()
{
    std::ios_base::sync_with_stdio(false); 
    int t;

    cin>>t;

    
    while(t--)
    {
        int n;
        cin>>n;

        vector<int> arr;

        int total = n;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(arr[i]==arr[j])
                    break;
                else if(check(arr,i,j))
                    total=total+(j-i+1);
                else
                    break;            
            }
        }

        cout<<total<<endl;
    }
return 0;
}