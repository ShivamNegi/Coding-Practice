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

int main()
{
    node * head = NULL;
    head = createnode(head, 0);
    node * prev = head;

    for(int i = 0; i < 5; i++)
    {
        node * temp = insertnode(prev, i);
        prev = temp;
    }

    return 0;
}