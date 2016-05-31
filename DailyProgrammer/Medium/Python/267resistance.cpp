#include<iostream>
#include<map>
#include<string.h>
#include<stdio.h>

using namespace std;

int main()
{
    int no;
    cin>>no;

    char arr[no];

    for(int i = 0; i < no; i++)
        cin>>arr[i];

    map<string, int>connection;
    int inpno;
    cin>>inpno;

    for(int i =0; i < inpno; i++)
    {
        char a[2], b[2];
        cin>>a>>b;        
        int val;
        cin>>val;
        connection[strcat(a, b)] = val;
    }

    return 0;
}