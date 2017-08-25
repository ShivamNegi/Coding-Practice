#include <iostream>
#include <cmath>

using namespace std;

struct node
{
    int data;
    node * next;
};

node * createnode(int data)
{
    node * temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node * insertnode(node * head, int data)
{
    if(head)
    {
        node * trav = head;

        while(trav->next)
            trav = trav->next;

        node * temp = createnode(data);
        trav->next = temp;

        return head;
    }
    else
    {
        node * temp = createnode(data);
        return temp;
    }
}

int bintodec(node * head)
{
    node * trav = head;
    int uni = 0, tens = 0;

    while(trav)
    {
        uni = trav->data;
        tens = tens * 2 + uni;
        trav = trav->next;
    }

    return tens;   
}

int main()
{
    node * head = NULL;
    int t;
    cin>>t;

    while(t--)
    {
        int no;
        cin>>no;
        head = insertnode(head, no);
    }

    cout<<bintodec(head)<<endl;

    return 0;
}