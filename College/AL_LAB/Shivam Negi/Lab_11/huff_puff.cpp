#include <iostream>

using namespace std;

struct pair
{
    char ch;
    int y;
};

struct node
{
    pair data;
    node * next;
};

struct two_pair
{
    pair first, second;
};

struct value_tree
{
    int value;
    two_pair data;
    value_tree * left, * right;
}

node * insert_node(node * head, pair data)
{
    if(head)
    {
        node * temp = new node;
        temp->data.ch = data.ch;
        temp->data.y = data.y;
        temp->next = NULL;
        return temp;
    }
    else
    {
        node * trav = head;
        
        while(trav->next)
            trav = trav->next;
            
        node * temp = new node;
        temp->data.ch = data.ch;
        temp->data.y = data.y;
        temp->next = NULL;
        trav->next = temp;
    }
    return head;
}

node * sort(node * head)
{
    
}

int main()
{
    int n;
    node * head = NULL;
    cout<<"Enter the number of elements: ";
    cin>>n;
    
    for(int i = 0; i < n; i++)
    {
        pair a;
        cout<<"Enter the alpha and its value: ";
        cin>>a.ch>>a.y;
        head = insert_node(head, data);
    }
    
    for(int i = 0; i < n; i++)
    {
        head = sort(head);
    }
    return 0;
}
