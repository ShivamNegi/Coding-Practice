#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    node * left, * right;
};

node * insert_node(node * head, int data)
{
    if(head)
    {
        node * trav = head;
        bool left = false;

        while(true)
        {
            if(trav->data < data)
                {
                    if(trav->right)
                        trav = trav->right;
                    else
                        break;
                }
            else if(trav->data > data)
                {
                    if(trav->left)
                        trav = trav->left;
                    else 
                        {
                            left = true;
                            break;
                        }
                }
            else
                return head;
        }
        node * temp = new node;
        temp->data = data;
        temp->left = temp->right = NULL;
        if(left)
            trav->left = temp;
        else
            trav->right = temp;
    }
    else
    {
        node * temp = new node;
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    return head;
}

bool ispresent(node * head, int data)
{
    node * trav = head;

    while(true)
    {
        if(data > trav->data)
        {
            if(trav->left)
                trav = trav->left;
            else
                return true;
        }
        if(trav->data > data)
        {
            if(trav->right)
                trav = trav->right;
            else
                return true;
        }
        else
            return false;
    }
    return true;
}

void display(vector<long long> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" " ;
    cout<<endl;
}

long long get_val(long long len)
{
    long res = 0;
    for(long long i = 1; i <= len / 2; i++)
    {
        res += (i * (len - i + 1));
    }
    res *= 2;
    if(len % 2 == 0)
        return res;
    else
        res += pow((len / 2 + 1), 2);
    return res;
}

long long res(vector<long long> a)
{
    long long res_sum = 0;
    int pos = 0, counter = 0;
    node * head = NULL;
    vector<long long> prev_eles;

    for(int i = 0; i < a.size(); i++)
    {  
        if(ispresent(head, a[i]))
        {
            long long len = counter;
            //cout<<len<<endl;

            int j;
            for(j = pos; j < a.size(); j++)
            {
                if(a[j] == a[i])
                {
                    break;
                }
            }        

            //cout<<j<<"i:"<<i<<endl;
            res_sum += (get_val(len)- get_val(i - j - 1));

            i = j;            
            pos = j + 1;            
            counter = 0;
            //cout<<"new beginning";
            free(head);
            head = NULL;
        }
        else
        {
            head = insert_node(head, a[i]);
            counter++;            
            //display(prev_eles);
        }
    }
    long long len = prev_eles.size();
    res_sum += get_val(len);

    return res_sum;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long> a;

        for(int i = 0; i < n; i++)
        {
            long long no;
            cin>>no;
            a.push_back(no);
        }

        cout<<res(a)<<endl;
    }
    return 0;
}