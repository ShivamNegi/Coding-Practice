#include <iostream>

using namespace std;

struct node
{
    int data;
    struct node * next;
};

node * create_node(int data)
{
    node * temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node * insert_node(node * head, int data)
{
    if(head)
    {
        node * temp = create_node(data);
        node * trav = head;

        while(trav->next)
            trav = trav->next;

        trav->next = temp;
        return head;
    }
    else
        return create_node(data);
    return head;
}

node * reverse(node * head)
{
    node * prev, *curr, * next;
    prev = NULL;
    curr = head;

    while(curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void display(node * head)
{
    node * trav = head;

    while(trav)
    {
        cout<<trav->data<<"\t";
        trav = trav->next;
    }
    cout<<endl;
}

int main()
{
    node * head;
    for(int i = 0; i < 5; i++)
        head = insert_node(head, i);

    display(head);
    head = reverse(head);
    display(head);
    return 0;
}