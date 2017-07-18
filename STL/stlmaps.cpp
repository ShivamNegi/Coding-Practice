#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
    All map operations are performed in O(log n) time complexity.
    Insertion
    Deletion
    Searching
    Also the map is sorted respect to the first value.
*/

void display(map<string, int> hash)
{
    for(map<string, int>:: iterator it = hash.begin(); it != hash.end(); it++)
    {
        cout<<it->first<<"\t"<<it->second<<endl;
    }
}

int main()
{
    map<string, int> hash;
    int len;
    cin>>len;

    for(int i = 0; i < len; i++)
    {
        string inp;
        int no;
        cout<<"Enter the string: ";
        cin>>inp;
        cout<<"Enter the number: ";
        cin>>no;
        hash[inp] = no;
    }
    display(hash);
    return 0;
}