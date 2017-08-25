#include <iostream>

using namespace std;

struct node
{
    int data;
    node * next;
};

node * createnode(int data)
{
    node * temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


node * insertnode(node * head, int data)
{
    if(head)
    {
        node * trav = head;

        while(trav->next)
            trav = trav->next;

        node * temp = createnode(data);
        trav->next = temp;
        return head;
    }
    return createnode(data);
}

void display(node * head)
{
    node * trav = head;

    while(trav)
    {
        cout<<trav->data<<" ";
        trav = trav->next;
    }
    cout<<endl;
}

// using a little more memory this is an O(N) algorithm
node * reverse(node * head)
{
    node * nextptr = head->next;
    head->next = NULL;
    node * cur = nextptr, * prev = head;

    while(cur)
    {
        // temp variable
        nextptr = cur->next;
        // swapping
        cur->next = prev;
        // updating
        prev = cur;
        cur = nextptr;
    }

    return prev;
}

// reversing on a particular data point
node * reverse(node * head, int n)
{
    node * trav;

    trav = head;
    if(trav->data == n)
        return reverse(head);
    while(trav->next->data != n)
        trav = trav->next;

    node * breakptr = trav;

    breakptr->next = reverse(trav->next);

    return head;
}

node * reverse_kth(node * head, int k)
{
 node * prev, * cur, * next;
 prev = cur = NULL;
 next = head;
 node * phead = head;

 while(next)
 {
	bool flag = true;
	for(int i = 0; i < k; i++)
	{
		if(!next)
		{
			flag = false;
			break;
		}
		cur = next;
		next = next->next;
		cur->next = prev;
		prev = cur;
	}
	if(flag)
	{
		phead->next = next;
		cur = prev = head;
	}
 }
 return cur;
}


int main()
{
    node * head = NULL;

    for(int i = 0; i < 5; i++)
    {
        head = insertnode(head, i);
    }

    display(head);
    head = reverse(head);
    display(head);
    head = reverse_kth(head, 2);
    display(head);
    return 0;
}
