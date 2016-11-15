#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node *left, *right;
}node;

node * create_node(int data)
{
	node * temp = (node *) malloc(sizeof(node));
	temp->left = temp->right = NULL;
	temp->data = data;
	return temp;
}

int height(node * head)
{
	if(!head)
		return 0;
	int left, right;
	left = right = 0;
	
	if(head->left)
		left = height(head->left);
	if(head->right)
		right = height(head->right);
	return left > right? left + 1: right + 1;
}

node * check_avl(node * head)
{
	if(height(head->left) - height(head->right) < -1)
	{
		node * temp = head->right;
		// right right
		if(height(temp->left) - height(temp->right) < 0)
		{
			head->right = temp->left;
			temp->left = head;
			return temp;
		}
		// right left
		else
		{			
            node * temp1 = temp->left;
			temp->left = temp1->right;
			temp1->right = temp;
			head->right = temp1->left;
			temp1->left = head;
			return temp1;
		}
	}
	else if(height(head->left) - height(head->right) > 1)
	{
		node * temp = head->left;
		// left right
		if(height(temp->left) - height(temp->right) < 0)
		{			
			node * temp1 = temp->right;
			temp->right = temp1->left;
			temp1->left = temp;
			head->left = temp1->right;
			temp1->right = head;
			return temp1;
		}
		// left left
		else
		{
			head->left = temp->right;
			temp->right = head;
			return temp;
		}
	}
	return head;
}

node * insert_bst(node * head, int data)
{
	if(!head)
		return create_node(data);
	if(data > head->data)
		{
			if(head->right)			
				head->right = insert_bst(head->right, data);
			else 
				head->right = create_node(data);
		}
	else
		{
			if(head->left)
				head->left = insert_bst(head->left, data);
			else
				head->left = create_node(data);
		}
	return check_avl(head);
}

void inorder(node * head)
{
	if(head)
	{
		inorder(head->left);
		printf(" %d", head->data);
		inorder(head->right);
	}
}

void postorder(node * head)
{
	if(head)
	{
		postorder(head->left);
		postorder(head->right);
		printf(" %d", head->data);
	}
}

void preorder(node * head)
{
	if(head)
	{
		printf(" %d", head->data);
		preorder(head->left);
		preorder(head->right);		
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
 	 	 head = insert_bst(head, data);
 	 	 printf("\nInorder:\t");
 	 	 inorder(head);
 	 	 printf("\nPostorder:\t");
 	 	 postorder(head);
 	 	 printf("\nPreorder:\t");
 	 	 preorder(head);
 	 	 printf("\n");
 	 	}
 	 else
 	 	break;
 	}
 	return 0;
}
