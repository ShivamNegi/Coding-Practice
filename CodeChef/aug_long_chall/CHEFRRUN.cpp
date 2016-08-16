#include <iostream>

using namespace std;

struct node
{
    int data;
    node * next;
};

node * insert_circular(node * head, int data)
{
    if(head)
    {
        node * trav = head->next;

        while(trav->next != head)
            trav = trav->next;

        node * temp = new node;
        temp->data = data;
        temp->next = head;
        trav->next = temp;        
    }
    else
    {
        node * temp = new node;
        temp->next = temp;
        temp->data = data;
        return temp;
    }
    return head;
}

node * next(node * head, int jmp)
{
    node * trav = head;
    for(int i = 0; i < jmp; i++)
        trav = trav->next;
    return trav;
}

bool jump_check(node * head, int n)
{
    int sum = head->data;
    bool flag = false;

    while(sum < n + 1)
    {
        node * trav = next(head, )
    }
    return flag;
}

int main()
{
    int t;

    while(t--)
    {
        int n;
        cin>>n;

        node * head;

        for(int i = 0; i < n; i++)
        {
            int data;
            cin>>data;            
            head = insert_circular(head, data);
        }

        int counter = 0;
        for(int i = 0; i < n; i++)
        {
            node * trav = head;
            for(int j = 0; j < i; j++)
            {
                trav = trav->next;
            }
            if(jump_check(trav))
            {
                counter ++;
            }        
        }
    }
    return 0;    
}
