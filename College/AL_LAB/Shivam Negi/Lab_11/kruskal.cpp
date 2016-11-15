#include <iostream>

using namespace std;

class Sets
{
    int *eles;
    int l;
    public:
    void Makeset(int x)
    {
        eles = (int *)malloc(sizeof(int));
        l = 1;
        eles[0] = x;
    }
    int find(edges x)
    {
        int v1, v2;
        v1 = x.v1;
        v2 = x.v2;
        int i;
        bool flag1, flag2;
        flag1 = flag2 = false;
        for(i = 0; i < l; i++)
        {
            if(eles[i] == v1)
                flag1 = true;
            if(eles[i] == v2)
                flag2 = true;
        }
        return flag1 && flag2;
    }
    void union()
    {
    }
};

class llSets
{
    Sets data;
    llSets * next;
};

class edges
{
    int v1, v2, w;
    public:
    edges(int a, int b, int wt)
    {
        v1 = a;
        v2 = b;
        w = wt;
    }
};

llSets * insert_node(llSets * head, int data)
{
    if(head)
    {
        llSets * temp = new llSets;
        llSets.Makeset(data);
        llSets.next = NULL;
        return temp;
    }
    else
    {
        llSets * trav = head;
        while(trav->next)
            trav = trav->next;
            
        llSets * temp = new llSets;
        llSets.Makeset(data);
        llSets.next = NULL;        
        trav = temp;
    }
    return head;
}

llSets
int main()
{
    return 0;
}
