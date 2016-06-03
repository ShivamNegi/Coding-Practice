#include <bits/stdc++.h>

using namespace std;

struct node
{
    int no;
    node * next;
}*head = NULL;

node * insertnode(node * head, int data)
{
    if(head)
    {
        node * trav;
        trav = head;
        while(trav->next)
            {trav = trav->next;}
        node * tempnode;
        tempnode = new node;
        tempnode->no = data;
        tempnode->next = head;
        trav->next = tempnode;
    }
    else
    {
        node * tempnode;
        tempnode = new node;
        tempnode->no = data;
        tempnode->next = head;
        head = tempnode;
    }
    return head;
}

node * removenode(node * head)
{
    head->next = head->next->next;
    return head;
}

void display(node * head)
{
    cout<<head->no<<" ";
    node * trav = head->next;
    while(trav != head)
        { 
            cout<<trav->no<<" ";
            trav = trav->next;
        }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;


    }

    return 0;    
}