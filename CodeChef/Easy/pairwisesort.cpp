#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector< pair<int, int> > &arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        int no;
        cin>>no;
        arr.push_back( make_pair(no, 0 ));
    }
    for(int i = 0; i < size; i++)
    {
        int no;
        cin>>no;
        arr[i].second = no;
    }
}

void display(vector< pair<int, int> > arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        
        cout<<arr[i].first<<"\t"<<arr[i].second;      
        cout<<endl;
    }
}

bool compare(const pair<int, int>&i, const pair<int, int>&j)
{
    return i.second < j.second;
}

int main()
{
 int n;

 cout<<"How  many numbers would you like to enter? ";
 cin>>n;

 vector< pair<int, int> > arr;

 input(arr, n);
 cout<<endl;
 sort(arr.begin(), arr.end(), compare);
 display(arr);
 return 0;
}