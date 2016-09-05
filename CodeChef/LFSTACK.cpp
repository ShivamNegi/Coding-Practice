#include <bits/stdc++.h>

using namespace std;

struct node
{
    int pos;
    vector< node *> next;
};

node * createnode(node * head, int pos)
{
    node * temp = new node;
    temp->pos = 0;
    return temp;
}

node * insertnode(node * head, int pos)
{
    node * temp = new node;
    temp->pos = pos;
    head->next.push_back(temp);
    return temp;
}

void getorder(vector< vector<int> > arr, vector<int> input, int size)
{
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if()
        }
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector< vector<int> > arr(n);
        int size, input_size = 0;

        cin>>size;

        for(int i = 0; i < size; i++)
        {
            int arr_size;
            cin>>arr_size;
            input_size += arr_size;

            for(int j = 0; j < arr_size; j++)
            {
                int no;
                cin>>no;

                arr[i].push_back(no);
            }
        }

        vector<int> input;

        for(int i = 0; i < input_size; i++)
        {
            int no;
            cin>>no;

            input.push_back(no);
        }

        getorder(arr, input, size);
    }

    return 0;
}