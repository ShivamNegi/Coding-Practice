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
        temp->data = data;
        trav->next = temp;
        temp->next = NULL;

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

node * merge(node * head1, node * head2)
{
    node * head = NULL, * trav = NULL;

    if(head1->data < head2->data)
    {
        trav = new node;
        trav->data = head1->data;
        trav->next = NULL;
        head1 = head1->next;
    }
    else
    {
        trav = new node;
        trav->data = head2->data;
        trav->next = NULL;   
        head2 = head2->next;
    }

    head = trav;
    while(head1 && head2)
    {
        if(head1->data < head2->data)
        {
            node * temp = new node;
            temp->data = head1->data;
            temp->next = NULL;
            trav->next = temp;
            trav = temp;
            head1 = head1->next;
        }
        else
        {
            node * temp = new node;
            temp->data = head2->data;
            temp->next = NULL;
            trav->next = temp;
            trav = temp;
            head2 = head2->next;   
        }
    }

    while(head1)
    {
        trav->next = head1;
        trav = trav->next;
        head1 = head1->next;
    }

    while(head2)
    {
        trav->next = head2;
        trav = trav->next;
        head2 = head2->next;
    }


    return head;
}


int main()
{
    node * head1, * head2, * head3;
    head1 = head2 = head3 = NULL;

    for(int i = 0; i < 3; i++)
    {
        int n;
        cout<<"Enter the number of elements to be inserted: ";
        cin>>n;

        while(n--)
        {
            int no;
            cin>>no;

            if(i == 0)
                head1 = insertnode(head1, no);
            else if(i == 1)
                head2 = insertnode(head2, no);
            else
                head3 = insertnode(head3, no);
        }
    }

    // display(head1);
    // display(head2);
    // display(head3);

    node * res = NULL;
    res = merge(head1, head2);
    node * res1 = NULL;
    res1 = merge(res, head3);
    display(res1);
    return 0;
}