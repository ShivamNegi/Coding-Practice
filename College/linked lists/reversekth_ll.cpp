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

node * reverse(node * head, int k, node * prev)
{
 node * cur, * next;
 cur = NULL;
 next = head;
 int counter = 0;
 
 while(next && counter < k)
 {
 	cur = next;
 	next = next->next;
 	cur->next = prev;
 	prev = cur;
 	counter++;
 }
 
 return cur;
}

node * reversekth(node * head, int k)
{
 node * start = head;
 while(start)
 {
  node * end = start;
  for(int i = 0; i < k && end; i++)
  	end = end->next;
  
  start = reverse(start, k, end);
  end = start;
 }
}

node * add_eve_end(node * head)
{
    node * trav = head->next;
    node * prev = head;
    node * end = head;
    
    while(end->next)
        end = end->next;

    node * upend = end;
    while(trav != end && prev != end)
    {
        prev->next = trav->next;
        upend->next = trav;
        trav->next = NULL;

        upend = upend->next;
        prev = prev ->next;
        trav = prev->next;
    }

    return head;
}

int main()
{
	node * head = NULL;

    for(int i = 0; i <= 6; i++)
    {
        head = insertnode(head, i);
    }

    display(head);
    //head = reversekth(head, 2);
    head = add_eve_end(head);
    display(head);
 	return 0;
}
