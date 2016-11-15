#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node * next;
};

void init(node a[], int size)
{
	for(int i = 0; i < size; i++)
	{
		a[i].data = i;
		a[i].next = NULL;
	}
}

void insert_ele(node a[], int data, int size)
{
	int pos = data % size;

	if(a[pos].next)
	{
		node * trav = a[pos].next;

		while(trav->next)
			trav = trav->next;

		node * temp = new node;
		temp->data = data;
		temp->next = NULL;
		trav->next = temp;
	}
	else
	{
		node * temp = new node;
		temp->data = data;
		temp->next = NULL;
		a[pos].next = temp;
	}
}

bool search_ele(node a[], int data, int size)
{
	int pos = data % size;

	node * trav = a[pos].next;

	while(trav)
	{
		if(trav->data == data)
			return true;
		trav = trav->next;
	}
	return false;
}

void display(node a[], int size)
{
	for(int i = 0; i < size; i++)
	{
		cout<<i<<": ";
		node * trav = a[i].next;
		while(trav)
		{
			cout<<trav->data<<"->";
			trav = trav->next;
		}
		cout<<endl;
	}
}

int main()
{
	int n;

	cout<<"Enter the size of the hash table: ";
	cin>>n;

	node a[n];
	init(a, n);

	while(true)
	{
		bool flag = false;
		int x, data;
		cout<<"What would you like to do?\n";
		cout<<"1.Insert\n2.Search\n3.Display\n:: ";
		cin>>x;

		switch(x)
		{
			case 1:
					cout<<"Enter the number: ";
					cin>>data;

					insert_ele(a, data, n);
					break;
			case 2:
					cout<<"Enter the data to be searched: ";
					cin>>data;

					if(search_ele(a, data, n))
						cout<<"Found\n";
					else
						cout<<"missing\n";
					break;
			case 3:
					display(a, n);
					break;
			default:
					flag = true;
					break;
		}

		if(flag)
			break;
	}
	return 0;
}