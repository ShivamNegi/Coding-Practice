#include <iostream>
#include <vector>
#include <set>
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

    vector<int> a;
    for(int i = 0; i < t; i++)
    {
        int no;
        cin>>no;
        a.insert(a.begin(), no);
    }

    vector<int> myvector(a.begin(), a.end());
    //cout<<count(a.begin(), a.end(), 2)<<endl;
    //display(a);

    /*if (equal(myvector.begin(), myvector.end(), a) )
        cout << "The contents of both sequences are equal.\n";
    else
        cout << "The contents of both sequences differ.\n";*/

    display(myvector);
    cout<<*min_element(myvector.begin(), myvector.end())<<endl;
    return 0;
}