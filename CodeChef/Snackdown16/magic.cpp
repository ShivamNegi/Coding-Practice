/*
    In this program I have used container type for loops in C++ !!
    Plus reverse function in algorithms this is so cool!
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> arr)
{
    for(auto no: arr)
        {cout<<no<<" ";}
    cout<<endl;
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

    sort(a.begin(), a.end());  

    display(a);
    reverse(a.begin(), a.end());
    display(a);

    cout<<endl;
    return 0;
}