#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector<int> nextiter(vector<int> a)
{
    for(int k = 0; k < a.size(); k++)
        {
            if(k + 1 < a.size())
                a.insert(a.begin() + k + 1, a[k] + a[k + 1]);
                k++;
        }
    return a;
}

vector<int> nextotheriter(vector<int> a, bool flag)
{    
    vector<int> temp;
    if(flag)
        for(int k = 1; k < a.size(); k++)
        {
            temp.push_back(a[k] + a[k - 1]);
            if(k + 1 != a.size())
                temp.push_back(a[k]);
        }
    else
    {
        temp.push_back(a[0]);
        for(int k = 1; k < a.size(); k++)
        {
            temp.push_back(a[k] + a[k - 1]);            
            temp.push_back(a[k]);
        }
    }
    return temp;
}

int main()
{
    int n;
    cin>>n;

    vector<int> a;

    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        a.push_back(no);
    }

    for(int i = 0; i < 5; i++)
    {
        a = nextotheriter(a, false);
        display(a);
    }
    return 0;
}