#include <iostream>

using namespace std;

int dist[100];
void djikstra(int graph[][100], int v, int source)
{
    bool marked[v];
    
    for(int i = 0; i < v; i++)
    {
        dist[i] = graph[source - 1][i];
        marked[i] = false;
    }
    
    dist[source - 1] = 0;
    marked[source - 1] = true;
    int ini_dist = 0, curr = source - 1;
    
    for(int i = 0; i < v - 1; i++)
    {
        int min_val = 999, pos;
        for(int j = 0; j < v; j++)
        {
            if(dist[j] < min_val && !marked[j])
            {
                min_val = dist[j];
                pos = j;
            }
        }
        ini_dist = min_val;
        marked[pos] = true;
        
        for(int j = 0; j < v; j++)
        {
            int val = ini_dist + graph[pos][j];
            if(val < dist[j] && !marked[j])
                dist[j] = val;
        }
    }
}

void display(int v)
{
    int len = v;
    
    cout<<"Shortest path to all the other edges is\n";
    for(int i = 0; i < len; i++)
    {
        cout<<dist[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int v, e;
    cout<<"Enter the number of vertices: ";
    cin>>v;
    
    int graph[100][100];
    cout<<"Enter the edge matrix:\n";
    for(int i = 0; i < v; i++)
    {
        for(int j = 0; j < v; j++)
        {
            cin>>graph[i][j];
        }    
    }
    
    int source;
    cout<<"Enter the start vertex: ";
    cin>>source;
    djikstra(graph, v, source);
    display(v);
    
    return 0;
}
