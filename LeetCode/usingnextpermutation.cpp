#include<bits/stdc++.h>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

void displayarr(int a[], int n)
{
    for(int i = 0; i < n; i++)
        {
            cout<<a[i]<<"\t";
        }
    cout<<endl;
}

int main()
{
    
    // trying with vectors
    vector<int> arr;

    for(int i = 0; i < 3; i++)
    {
        int no;
        cin>>no;
        arr.push_back(no);
    }

    while(next_permutation(arr.begin(), arr.end()) )
    {
        display(arr);
    }
    

    // trying with strings

    
    string name;

    cin>>name;

    while(next_permutation(name.begin(), name.end()))
    {        cout<<name<<"\t";            }
    


    // trying with normal arrays
    int a[5];

    for(int i = 0; i < 3; i++)
    {
        cin>>a[i];
    }

    do
    {
        displayarr(a, 3);
    }while(next_permutation(a, a+3));

    // trying with character arrays
    char str[20];

    int n;
    cin>>str;

    do
    {
        puts(str);
    }while(next_permutation(str, str + strlen(str)));

    cout<<endl;
    return 0;
}