#include <iostream>

using namespace std;

struct node
{
    int data;
    node * left, * right;
};



node * insertnode(node * head, int data)
{
    if(head)
    {
        char ch;
        cout<<"Where would you like to insert the next node: left(l) or right(r): ";
        cin>>ch;

        if(ch == 'l')
            head->left = insertnode(head->left, data);
        else
            head->right = insertnode(head->right, data);
    }
    else
    {
        node * temp = new node;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
}


int main()
{
    node * head = NULL;
    bool flag = false;
    
    while(true)
    {
        cout<<"What would you like to do?\n";
        cout<<"1.Insert node\n2.Level Order Display\nExit\n";
        int x;
        cin>>x;

        switch(x)
        {
            case 1:
                    int data;
                    cout<<"Enter the data: ";
                    cin>>data;
                    head = insertnode(head, data);
                    break;
            case 2:
                    levelorder(head);
                    cout<<endl;
                    break;            
            default:
                    flag = true;
        }
        if(flag)
            break;
    }
    return 0;
}