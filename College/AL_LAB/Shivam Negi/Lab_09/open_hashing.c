#include <stdio.h>
#include <stdlib.h>

int n;

typedef struct Node
{
    int data;
    struct Node * next;
}node;

node * create_node(int data)
{
    node * t = (node *)malloc(sizeof(node));
    t->data = data;
    t->next = NULL;
    return t;
}

void insert(node * ll[], int data)
{
    int pos = data % n;
    
    node * t = create_node(data);
    t->next = ll[pos]->next;
    ll[pos]->next = t->next;
}

int find(node * ll[], int data)
{
    int pos = data % n;
    
    node * head = ll[pos]->next;
    while(head != NULL)
    {
        printf("%d\n",head->data);
        if(head->data == data)
            return 1;
        head = head->next;
    }
    return 0;
}




int main()
{    
    int t, flag = 0, i;
    
    printf("Enter the mod function: ");
    scanf(" %d", &n);
    
    node * ll[n];
    for(i = 0; i < n; i++)
        ll[i] = create_node(-1);
    
    while(1)
    {
        int x, data;
        printf("\n1.Insert\n2.Search\n3.Exit\nInput: ");
        scanf(" %d", &x);
        
        switch(x)
        {
            case 1:
                    printf("Enter the data to be inserted: ");
                    scanf(" %d", &data);
                    insert(ll, data);
                    break;
            case 2:
                    printf("Enter the data to be searched: ");
                    scanf(" %d", &data);
                    
                    if(!find(ll, data))
                        printf("Missing\n");
                    else
                        printf("Found\n");
                    break;
            case 3:
                    flag = 1;
                    break;
        }
        
        if(flag)
            break;
    }
    return 0;
}
