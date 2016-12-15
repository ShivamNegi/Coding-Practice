#include <iostream>

using namespace std;

struct node
{
	int val;
	struct node * next;
};

node * create_node(int val)
{
	node * temp = new node;
	temp->val = val;
	temp->next = temp;
	return temp;
}

node * insert_acc(node * head, int x, int y)
{
	node * trav = head;

	do
	{
		if(trav->val == x)
		{
			node * temp = create_node(y);
			temp->next = trav->next;
			trav->next = temp;
			trav = trav->next;			
		}
		trav = trav->next;
	}while(trav != head);
	return head;
}

int get_len(node * head)
{
	node * trav = head->next;
	int val = 1;

	while(trav != head)
	{
		val++;
		trav = trav->next;
	}
	return val;
}
int main()
{
	std::ios_base::sync_with_stdio(false);
	node * head = create_node(0);

	int n, l, r;
	cin>>n>>l>>r;

	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin>>x>>y;
		head = insert_acc(head, x, y);
	}

	int len = get_len(head);
	int start = l % len;

	node * trav = head;
	for(int i = 0; i < start; i++)
		trav = trav->next;

	for(int i = l; i < r; i++)
	{
		cout<<trav->val<<" ";
		trav = trav->next;
	}
	cout<<endl;

	return 0;
}