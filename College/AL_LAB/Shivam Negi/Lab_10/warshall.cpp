#include <iostream>

using namespace std;

bool graph[50][50];
int counter = 0;

void display(int v)
{
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<"\n\n\n";
    }
}

void warshall(int v)
{
    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
                counter++;
            }
        }
    }
}

int main()
{
    int v;
    cout<<"Enter the number of vertices of the graph: ";
    cin>>v;
    
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            graph[i][j] = false;
        }
    }
    
    for(int i = 0; i < v; i++)
    {
        cout<<"Enter the edges for "<<i<<endl;
        cout<<"End with a -1\n";
        
        int no;
        cin>>no;
        
        while(no != -1)
        {
            graph[i][no] = true;
            cin>>no;
        }        
    }
    
    display(v);
    warshall(v);
    display(v);
    cout<<counter<<endl;
    return 0;
}
