#include <iostream>
#include <cmath>

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

void inorder(node * head)
{
    if(head)
    {
        inorder(head->left);
        cout<<head->data<<" ";
        inorder(head->right);
    }
}

void clear(int a[])
{
    for(int i = 0; i < 100; i++)
        a[i] = 0;
}

void getnodes(node * head, int a[], int i)
{
    if(head)
    {
        getnodes(head->left, a, i * 2);
        a[i] = head->data;
        getnodes(head->right, a, i * 2 + 1);
    }
}

void display(int a[])
{
    for(int i = 0; i < 20; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int getheight(node * head)
{
    int x, y;
    if(head)
    {
        x = getheight(head->left);
        y = getheight(head->right);
    }
    else
        return 0;

    return x > y?x + 1: y + 1;
}

int main()
{
    node * head = NULL, * root = NULL;
    bool flag = false;
    
    while(true)
    {
        cout<<"What would you like to do?\n";
        cout<<"1.Insert node\n2.Inorder Display\n3.Extremas\nExit\n";
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
                    inorder(head);
                    cout<<endl;
                    break;
            case 3:
                    int a[100], h;
                    clear(a);
                    getnodes(head, a, 1);                    
                    h = getheight(head);

                    for(int k = h; k > 0; k--)
                    {
                        int left, right;
                        left = right = 0;
                        for(int i = pow(2, k - 1); i < pow(2, k); i++)
                        {
                            if(left == 0 && a[i] != 0)
                                left = a[i];
                            else if(a[i] != 0)
                                right = a[i];
                        }
                        if(k == 1)
                            cout<<left;
                        else if(right == 0)
                            cout<<left<<" ";
                        else
                            cout<<left<<" "<<right<<" ";

                    }
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