#include<stdio.h>
#include<stdlib.h>

int count1=0,count2=0;// count1:insertion, count2:deletion
typedef struct node
{
    int val;
    struct node *next;
}Node;

Node* insertnode(Node *root, int key)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->val = key;
    newnode->next = NULL;
    if(root==NULL){count1++;
        return newnode;}
    else
    {   count1++;
        Node *rt = root;
        while(rt->next!=NULL)
        {
            rt = rt->next;
        }
        rt->next = newnode;
        return root;
    }
}

void search(Node **list,int n, int key)
{
	int p = key%n;
	Node *temp = list[p];
	int flag = 0;
	int count=0;
	while(temp)
	{   
		count++;
		if(temp->val==key)
		{
			flag=1;
			break;
		}
		else
			temp = temp->next;
	}
	if(flag==1)
		printf("Search Successful\n");
	else
		printf("Search Unsuccessful\n");
		printf("Count : %d\n",count);
}

void printnode(Node *root)
{
    Node *rt = root;
    while(rt!=NULL)
    {
        printf("-> %d",rt->val);
        rt = rt->next;
    }
}

int main()
{
	int n,i,ch,key,x;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	Node **list = (Node **)malloc(n*sizeof(Node *));
   	for(i=0;i<n;i++)
    	{
   	     list[i] = NULL;
	}
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		int p = x%n;
		list[p] = insertnode(list[p],x);
		
	}printf("The count for insertions :%d\n",count1);
	
	for(i=0;i<n;i++)
   	{
        	printnode(list[i]);
        	printf("\t");
  	}
	do
	{
		printf("\n1. Search\n");
		printf("2. Exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : 
				printf("Enter key to be searched: ");
				scanf("%d",&key);
				search(list,n,key);
				break;
			case 2 : 
				break;
			default : 
				printf("Invalid Entry");
		}
	}while(ch!=2);
 return 0;	
}
