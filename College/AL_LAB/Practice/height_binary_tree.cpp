#include <iostream>

using namespace std;

struct node
{
	int data;
	struct node * left, *right;
};

node * create_node(int data)
{
	node * temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
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

	if(left > right)
		return left + 1;
	else
		return right + 1;
}

int main()
{
	node * head = create_node(1);
	head->right = create_node(1);
	head->right->right = create_node(1);
	head->right->right->right = create_node(1);
	head->right->right->right->right = create_node(1);
	head->left = create_node(1);
	head->left->left = create_node(1);
	head->left->right = create_node(1);
	head->left->right->right = create_node(1);

	cout<<height(head)<<endl;

	return 0;
}