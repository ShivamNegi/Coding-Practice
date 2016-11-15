/*
	write the menu driven on your own
*/
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int bool;

struct Node
{
 int data;
 struct Node *next;
};

typedef struct Node node;

node * insert(int data)
{
 node * temp = (node *) malloc(sizeof(node));
 temp->next = NULL;
 temp->data = data;
 return temp;
}

node * insertfront(node * head, int data)
{
 if(head)
	{
		node * temp = insert(data);
		temp->next = head;
		return temp;
	}
 return insert(data);
}

bool ispresent(node * head, int key)
{
 if(head)
	{
	 node * trav = head;

	 while(trav)
		{
			if(trav->data == key)
				return true;
			trav = trav->next;
		}
	}
 return false;
}

node * del_node(node * head, int data)
{
 if(head)
	{
	 if(head->data == data)
		{
			return head->next;
		}
     else
		{
			node * trav = head;
			while(trav->next->data != data)
				trav = trav->next;
			trav->next = trav->next->next;
		}
	}
 return head;
}

void display(node * head)
{
 node * trav = head;

 while(trav)
	{
		printf(" %d->", trav->data);
		trav = trav->next;
 	}
}

int main()
{
 node * head = NULL;

 return 0;
}

