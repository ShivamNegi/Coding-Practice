#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 1

struct Node
{
	int data;
	struct Node * next;
};

typedef struct Node node;

node * insert(int data)
{
	node * temp = (node *)malloc(sizeof(node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

node * addedge(node * head, int data)
{
 if(head)
	{
		node * trav = head;
		while(trav->next)
			trav = trav->next;

		trav->next = insert(data);
		return head;
	}
 return insert(data);
}

void display(node * head, int pos)
{
 if(head)
	{
	 node * trav = head;
 	 while(trav)
		{
			printf("%d->%d\n", pos, trav->data);
			trav = trav->next;
		}
	}
}


void display_adjlist(node * head[], int size)
{
 int i = 0;

 for(i = 0; i < size; i++)
	{
		display(head[i], i);
	}
}

int main()
{
 int size, i;
 printf("How many vertices? ");
 scanf(" %d", &size);

 node * head[size];

 for(i = 0; i < size; i++)
	{
		head[i] = NULL;
	}
	
 while(true)
	{
		int x, y;
		printf("Keep adding edges x, y\n");
		scanf(" %d %d", &x, &y);

		head[x] = addedge(head[x], y);
		head[y] = addedge(head[y], x);	

		char ch;
		printf("do you want to keep inserting? (y/n) ");
		scanf(" %c", &ch);
		if(ch == 'n')
			break;
	} 

 display_adjlist(head, size);

 return 0;
}
