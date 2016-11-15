#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data[2], pos;
    struct Node * left, * right, * middle;
}node;

node * create_node(int data)
{
    node * temp = (node *) malloc(sizeof(node));
    temp->pos = 0;
    temp->data[temp->pos++] = data;
    temp->left = temp->middle = temp->right = NULL;
    return temp;
}

int check_pos(node * head)
{
    
}

node * insert_2_3(node * head, int data)
{
    if(head)
        return create_node(data);
    else
        {
            int x;
            x = check_pos(head);
        }
}

int main()
{
    node * head = NULL;
    return 0;
}
