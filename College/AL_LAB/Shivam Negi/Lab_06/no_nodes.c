#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
 int data;
 struct Node * left, * right;
}node;

node * create_node(int data)
{
 node * temp = (node *) malloc(sizeof(node));
 temp->left = temp->right = NULL;
 temp->data = data;
 return temp;
}

node * insert_node(node * head, int data)
{
 if(head)
 	{
 	 node * trav = head;
	 
	 while(1)
	 	{
	 	 int x;
	 	 printf("left child? (1) or right child? (2)\n");
	 	 scanf(" %d", &x);
	 	 
	 	 if(x == 1)
	 	 	{
	 	 	 if(trav->left)
	 	 	 	trav = trav->left;
	 	 	 else
	 	 	 	{
	 	 	 		node * temp = create_node(data);
	 	 	 		trav->left = temp;
	 	 	 		break;
	 	 	 	}
	 	 	}
	 	 else
	 	 	{
	 	 	 if(trav->right)
	 	 	 	trav = trav->right;
	 	 	 else
	 	 	 	{
	 	 	 	 node * temp = create_node(data);
	 	 	 	 trav->right = temp;
	 	 	 	 break;
	 	 	 	}
	 	 	}
	 	}
	 return head;
 	} 
 return create_node(data); 
}

int cost = 0, counter = 0;
void inorder(node * head)
{
 counter++;
 if(head)
 	{
 	 inorder(head->left);
 	 cost++;
 	 inorder(head->right);
 	}
}

int main()
{
 node * head = NULL;

 while(1)
 	{
 	 int x;
 	 printf("1. Insert\n2. Exit\n");
 	 scanf(" %d", &x);
 	 
 	 if(x == 1)
 	 	{
 	 	 int data;
 	 	 printf("Enter the data: ");
 	 	 scanf(" %d", &data);
 	 	 head = insert_node(head, data);
 	 	}
 	 else
 	 	break;
 	}
 inorder(head);
 printf("The number of nodes in the tree are: %d\n", cost);
 //printf("The number of operations are: %d\n", counter);
 return 0;
}
