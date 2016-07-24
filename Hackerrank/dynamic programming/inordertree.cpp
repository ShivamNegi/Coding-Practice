#include <iostream>

using namespace std;

struct node
{
    int data;
    node * left, * right;
};

void inorder_trav(node * head)
{
    if(head)
    {
        inorder_trav(head->left);
        cout<<head->data<<"\t";
        inorder_trav(head->right);
    }
}

node * insert_node(node * head, int data)
{
    if(head)
    {
        if(head->data < data)
        {
            head->left = insert_node(head->left, data);
        }
        else
        {
            head->right = insert_node(head->right, data);
        }
    }
    else
    {
        node * temp = new node;
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
}

int main()
{
    node * head = NULL;

    for(int i = 0; i < 5; i++)
    {
        head = insert_node(head, i);
    }

    inorder_trav(head);

    return 0;
}