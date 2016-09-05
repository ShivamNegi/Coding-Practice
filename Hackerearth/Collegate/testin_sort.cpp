#include <bits/stdc++.h>

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
    int no;
    cin>>no;
    vector<int> a;
    for(int i = 0; i <  no; i++)
    {
        int n;
        cin>>n;
        a.push_back(n);
    }

    display(a);
    sort(a.begin() + 2, a.begin() + 5);
    display(a);
    return 0;
}