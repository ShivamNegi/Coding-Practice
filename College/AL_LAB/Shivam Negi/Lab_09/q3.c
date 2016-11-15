#include<stdio.h>
#include<stdlib.h>
int *insert(int *hash,int n,int key)
{
	int i=key%n;
	while(hash[i]!=-1)
		i=(i+1)%n;
	hash[i] = key; 
	return hash;
}
void search(int *hash,int n,int key)
{
	int p=key%n;
	int i=p;
	int count=0,flag=0;
	while(hash[p]!=-1)
	{
		count++;
		if(hash[p]==key)
		{		
			flag=1;
			break;
		}
		else
		{			
			p=(p+1)%n;
			if(i==p)
			break;
		}
	}
	if(flag==1)
		printf("Search Successful\n");
	else
		printf("Search Unsuccessful\n");
		printf("Count : %d\n",count);
}
int main()
{
	int n,i,ch,key,x;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int hash[n];
	for(i=0;i<n;i++)
		hash[i] = -1;
	printf("Enter the elements: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		insert(hash,n,x);
	}
	do
	{
		printf("\n1. Search element \n");
		printf("2. Exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 : printf("Enter key to be searched: ");
				scanf("%d",&key);
				search(hash,n,key);
				break;
			case 2 : 
				break;
			default : 
				printf("Invalid Entry");
		}
	}while(ch!=2);
	
}
