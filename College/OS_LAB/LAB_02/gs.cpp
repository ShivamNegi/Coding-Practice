#include <iostream>

using namespace std;

struct node
{
	int leftu;
	int leftl;
	int usedl;
	int usedu;
	node * left, * right;
};

node * create(int n)
{
	node * temp = new node;
	temp->leftu = n - 1;
	temp->leftl = n;
	temp->usedu = 1;
	temp->usedl = 0;
	temp->left = temp->right = NULL;
	return temp;
}

node * insertnode_left(node * head)
{
	node * temp = new node;
	temp->leftu = head->leftu - 1;
	temp->leftl = head->leftl;
	temp->usedu = head->usedu + 1;
	temp->usedl = head->usedl;
	temp->left = temp->right = NULL;
	return temp;
}

node * insertnode_right(node * head)
{
	node * temp = new node;
	temp->leftu = head->leftu;
	temp->leftl = head->leftl - 1;
	temp->usedu = head->usedu;
	temp->usedl = head->usedl + 1;
	temp->left = temp->right = NULL;
	return temp;
}

bool conditionsleft(node * head)
{
	if(head->leftu > 0)
		return true;
	return false;
}

bool conditionsright(node * head)
{
	head->usedl++;
	if(head->usedl <= head->usedu && head->leftu > 0)
		return true;
	return false;
}


void counttree(node * head, int& count)
{
	if(head)
	{
		counttree(head->left, count);
		if(!head->left && !head->right)
			count++;
		counttree(head->right, count);
	}
}

node * createtree(node * head)
{
	if(conditionsleft(head))
	{
		head->left = insertnode_left(head);
		head->left = createtree(head->left);		
	}
	if(conditionsright(head))
	{
		head->right = insertnode_right(head);
		head->right = createtree(head->right);
	}

	return head;
}

void inorder(node * head)
{
	if(head)
	{
		inorder(head->left);
		cout<<head->leftu<<" ";
		inorder(head->right);
	}
}


void found(int n)
{
	node * head = create(n);		
	head = createtree(head);
    int count = 0;
	counttree(head, count);
    //inorder(head);
    cout<<count<<endl;
}

int main()
{
    for(int i = 1; i < 5; i++)
	   found(i);
	return 0;
}
