#include <iostream>
#define INF 99

using namespace std;

int graph[50][50];
int counter = 0;

void display(int v)
{
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cout<<graph[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

void warshall(int v)
{
    for(int k = 0; k < v; k++)
    {
        for(int i = 0; i < v; i++)
        {
            for(int j = 0; j < v; j++)
            {
                int a = graph[i][j], b = graph[i][k] + graph[k][j];
                graph[i][j] = a > b ? b : a;
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
            graph[i][j] = INF;
        }
    }
    
    for(int i = 0; i < v; i++)
    {
        cout<<"Enter the edges for and weight "<<i<<endl;
        cout<<"End with a -1\n";
        
        int no;
        cin>>no;
        int wt;
        cin>>wt;
        
        while(no != -1)
        {
            graph[i][no] = wt;
            cin>>no;
            cin>>wt;
        }        
    }
    
    display(v);
    warshall(v);
    display(v);
    cout<<counter<<endl;
    return 0;
}
