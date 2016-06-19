#include <iostream>

using namespace std;

struct node
{
    char ch;
    node * next;
};

node * insertnode(node * head, char data)
{
    node * temp = new node;
    temp->ch = data;
    temp->next = head;

    return temp;
}

void display(node * head)
{
    node * temp = head;

    while(temp->next != 0)
    {
        cout<<temp->ch<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

char pop(node ** head)
{
    char ch = (*head)->ch;
    *head = (*head)->next;
    return ch;
}

int main()
{
    node * head = new node;
    head->next = NULL;

    string inp;
    cin>>inp;

    for(int i = 0; i < inp.length() / 2; i++)
    {
        head = insertnode(head, inp[i]);
    }

    int pos;

    if(inp.length() % 2 == 0)
    {
        pos = inp.length() / 2;
    }
    else
        pos = inp.length() / 2 + 1;
    bool flag = true;
    char ch = pop(&head);
    while(ch)
    {
        if(inp[pos++] != ch)
        {
            flag = false;
            break;
        }
        ch = pop(&head);
    }

    if(flag)
        cout<<"Palindrome\n";
    else
        cout<<"Not Palindrome\n";

    return 0;
}