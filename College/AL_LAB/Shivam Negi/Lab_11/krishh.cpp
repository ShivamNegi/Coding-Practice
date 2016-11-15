#include <iostream>
#include <stdlib.h>

using namespace std;

class Set
{
    int *eles;
    int len;
    
    public:
    void Makeset(int size)
    {
        eles = (int *)malloc(sizeof(int) * size);
        for(int i = 0; i < size; i++)
        {
            eles[i] = i;
        }
    }
    int find(int x)
    {
        return eles[x];
    }
    void union_set(int x, int y)
    {
        eles[x] = eles[y];
    }
};

struct edge
{
    int v1, v2, e;    
};

void copy(edge *a, edge * b)
{
    a->v1 = b->v1;
    a->v2 = b->v2;
    a->e = b->e;
}

void swap(edge *x, edge *y)
{
    edge temp;
    copy(&temp, x);
    copy(x, y);
    copy(y, &temp);    
}

void heapify(edge arr[], int n, int i)
{
    int largest = i;  
    int l = 2*i + 1;  
    int r = 2*i + 2;  
 
    if (l < n && arr[l].e > arr[largest].e)
        largest = l;
 
    if (r < n && arr[r].e > arr[largest].e)
        largest = r;
 
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
 
        heapify(arr, n, largest);
    }
}

void heapSort(edge arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
 
        heapify(arr, i, 0);
    }
}

void print_edge(edge ed[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout<<ed[i].v1<<"\t"<<ed[i].v2<<"\t"<<ed[i].e<<endl;
    }
}
int main()
{
    int v, e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    
    cout<<"Enter the number of edges: ";
    cin>>e;
    
    edge ed[e];
    cout<<"Enter the edges:\n";
    for(int i = 0; i < e; i++)
    {
        int x, y, wt;
        cin>>x>>y>>wt;
        ed[i].v1 = x;
        ed[i].v2 = y;
        ed[i].e = wt;
    }
    Set s;
    s.Makeset(v);
    heapSort(ed, e);
    int out[v][v];
    
    //init matrix
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
            out[i][j] = 0;
    }
    
    //out matrix
    for(int i = 0; i < e; i++)
    {
        int val1 = s.find(ed[i].v1);
        int val2 = s.find(ed[i].v2);
        if(val1 != val2)
            {
               s.union_set(ed[i].v2, ed[i].v1);
               out[ed[i].v2][ed[i].v1] = ed[i].e;
               out[ed[i].v1][ed[i].v2] = ed[i].e;
            }
    }
    
    //print matrix
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout<<out[i][j]<<"\t";
        }
        cout<<endl;
    }
    return 0;
}
