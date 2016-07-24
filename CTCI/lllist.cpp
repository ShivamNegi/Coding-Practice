#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

struct node
{
 int data;
 node * next;
};

node * insertnode(node * head, int data)
{
 if(head)
	{
 	 node * trav = head;
	 while(trav->next)
		trav = trav->next;
	 node * temp = new node;
	 temp->data = data;
	 temp->next = NULL;
	 trav->next = temp;
	 return head;
	}
 else
	{
 	 node * temp = new node;
	 temp->next = NULL;
	 temp->data = data;
	 return temp;
	}
}

node * deletenode(node * head, int data)
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
		 while(trav->next)
			{
 			 if(trav->next->data == data)
				{
					break;
				}
			 trav = trav->next;
			}
		 node * curr = trav->next;
		 trav->next = trav->next->next;
		 free(curr);
		}
	 return head;
	}
	return head;
}

void display(node * head)
{
 while(head)
	{
	 cout<<head->data<<" ";
	 head = head->next;
	}
 cout<<endl;
}

int main()
{
 node * head = NULL;
 for(int i = 0; i < 6; i++)
	head = insertnode(head, i);
 display(head);
 head = deletenode(head, 3);
 display(head);
 return 0;
}
