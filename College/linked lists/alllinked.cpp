#include <iostream>

using namespace std;

struct node
{
    int data;
    node * next;
};


node * insertnode(node * head, int data)
{
    if(head)
    {
        node * trav = head;

        while(trav->next)
            trav = trav->next;

        node * temp = new node;
        temp->next = NULL;
        temp->data = data;
        trav->next = temp;
        return head;
    }
    else
    {
        node * temp = new node;
        temp->data = data;
        temp->next = NULL;
        return temp;
    }
}

void display(node * head)
{
    node * trav = head;

    while(trav)
    {
        cout<<trav->data<<" ";
        trav = trav->next;
    }
    cout<<endl;
}

// using a little more memory this is an O(N) algorithm
node * reverse(node * head)
{
    node * nextptr = head->next;
    head->next = NULL;
    node * trav = nextptr, * prev = head;

    while(trav)
    {
        nextptr = trav->next;
        trav->next = prev;
        prev = trav;
        trav = nextptr;
    }

    return prev;
}

// reversing on a particular data point
node * reverse(node * head, int n)
{
    node * trav;

    trav = head;
    if(trav->data == n)
        return reverse(head);
    while(trav->next->data != n)
        trav = trav->next;

    node * breakptr = trav;

    breakptr->next = reverse(trav->next);

    return head;
}


int main()
{
    node * head = NULL;

    for(int i = 0; i < 5; i++)
    {
        head = insertnode(head, i);
    }

    display(head);
    head = reverse(head);
    display(head);
    head = reverse(head, 2);
    display(head);
    return 0;
}