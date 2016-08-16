#include <iostream>

using namespace std;

struct node
{
    int posx, posy;
    int prevx, prevy;
    node * next;
};

node * insertdoubly(node * head, int x, int y)
{
    if(head)
    {
        node * trav = head;

        while(trav->next)
            trav = trav->next;

        node * temp = new node;
        temp->posx = x;
        temp->posy = y;
        temp->prevx = trav->posx;
        temp->prevy = trav->posy;
        temp->next = NULL;

        return head;
    }
    else
    {
        node * temp = new node;
        temp->posx = temp->posy = 0;
        temp->prevy = temp->prevx = -1;
        temp->next = NULL;
        return temp;
    }
}

node * getnext(node * head, int a[][])
{

}

int main()
{
    int n;
    cin>>n;

    int a[n][n];
    for(int i = 0; i < n; i++)
    {   
        for(int j = 0; j < n;j ++)        
            cin>>a[i][j];
    }

    node * head = insertdoubly();

    while(checkifreached(head))
    {

    }

    return 0;
}