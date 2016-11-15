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
 else
 	{
 	 return create_node(data);
 	}
 return head;
}
 
/*void inorder(node * head)
{
 if(head)
 	{
 	 inorder(head->left);
 	 printf(" %d", head->data);
 	 inorder(head->right);
 	}
}*/

int height(node * head)
{
 int left, right;
 left = right = 0;
 
 if(head->left)
 	left = height(head->left);
 if(head->right)
 	right = height(head->right);
 	
 return left>right?left + 1: right + 1;
}

int cost = 0;
void diameter(node * head)
{
 int left, right;
 left = right = 0;
 
 if(!head)
 	return;
 else
 	{
 	 if(head->left)
	 	 left = height(head->left);
	 if(head->right)
	 	 right = height(head->right);
 	 
 	 int val = left + right + 1;
 	 cost = val > cost ? val : cost;
 	}
 diameter(head->left);
 diameter(head->right);
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
 // inorder(head);
 // printf("\n");
 diameter(head);
 printf("The diameter of the tree is: %d\n", cost);
 return 0;
}
