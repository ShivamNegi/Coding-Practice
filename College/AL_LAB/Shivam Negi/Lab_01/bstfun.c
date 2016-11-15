#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct Node * left, * right;
};

typedef struct Node node;

node * insert(int data)
{
	node * temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

node * insertnode(node * head, int data)
{
	if(head)
	{
		char ch;
		printf("Where would you like to insert? (l)eft or (r)ight: ");
		fflush(stdout);
		scanf(" %c", &ch);
	
		if(ch == 'l')
			{
				if(head->left)
					{
						head->left = insertnode(head->left, data);
					}
				else
					{
						head->left = insert(data);
					}
			}
		else
			{
				if(head->right)
					{
						head->right = insertnode(head->right, data);
					}
				else
					{
						head->right = insert(data);
					}
			}	
		return head;
	}
	
	return insert(data);
}

node * insertbst(node * head, int data)
{
	if(!head)
		return insert(data);
	if(data > head->data)
		{
			if(head->right)			
				head->right = insertbst(head->right, data);
			else 
				head->right = insert(data);
		}
	else
		{
			if(head->left)
				head->left = insertbst(head->left, data);
			else
				head->left = insert(data);
		}
	return head;
}

void inorder(node * head)
{
	if(head)
		{
			inorder(head->left);
			printf("%d\t",head->data);
			inorder(head->right);
		}
}

void postorder(node * head)
{
	if(head)
		{
			inorder(head->left);
			inorder(head->right);
			printf("%d\t",head->data);
		}
}

void preorder(node * head)
{
	if(head)
		{
			printf("%d\t",head->data);
			inorder(head->left);
			inorder(head->right);			
		}
}

bool searchnode(node * head, int data)
{
	bool flagl, flagr;
	flagl = flagr = false;
	if(head)
		{
		 flagl = searchnode(head->left, data);
		 if(data == head->data)
			return true;
		 flagr = searchnode(head->right, data);
		}
	return flagl || flagr;
}

int choose()
{
 int x;
 printf("Binary tree or BST? (1/0)");
 scanf(" %d", &x);
 return x;
}


int main()
{
 node * headbt, * headbst;
 headbt = headbst = NULL;
 int data;

 while(true)
	{
	 int x;
	 printf("\nWhat would you like to do?\n");
	 printf("1. Insert B.tree\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search Key\n");
	 scanf("%d", &x);
	 fflush(stdout);

	 switch(x)
		{
			case 1:
					printf("Enter the data: ");
					scanf("%d", &data);
					fflush(stdout);
					headbt = insertnode(headbt, data);
					break;
			case 2:
					if(choose())
						preorder(headbt);
					else
						preorder(headbst);
					break;
			case 3:
					if(choose())
						inorder(headbt);
					else
						inorder(headbst);

					break;
			case 4:
					if(choose())
						postorder(headbt);
					else
						postorder(headbst);
				
					break;
			case 5:
					printf("Enter the data to be searched: ");
					scanf("%d", &data);
					if(searchnode(headbt, data))
						printf("key found\n");
					else
						headbst = insertbst(headbst, data);
					break;
			default:
					exit(0);
		}
	}
 return 0;
}
