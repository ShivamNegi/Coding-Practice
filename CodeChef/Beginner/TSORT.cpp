#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        printf("%d\n", a[i]);
    }
}

int main()
{
    int t;
    cin>>t;

    vector<int> arr;

    for(int i = 0; i < t; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    sort(arr.begin(), arr.end());
    display(arr);

    return 0;
}