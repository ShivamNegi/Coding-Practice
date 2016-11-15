#include <iostream>
#define SIZE 10
#define INF 10e7

using namespace std;

int g[SIZE][SIZE];

void display(int a[], int size)
{
	cout<<endl;
	for(int i = 0; i < size; i++)
	{
		if(a[i] == INF)
			cout<<"0\t";
		else
			cout<<a[i]<<"\t";
	}
	cout<<endl;
}

void dijkstra(int source, int size)
{
 int dist[size];
 bool visited[size];

 // initializing the arrays
 for(int i = 0; i < size; i++)
 {
	dist[i] = g[source][i];
	visited[i] = false;
 }
 visited[source] = true;

 // iterating
 for(int i = 0; i < size - 1; i++)
 {
 	int min_val = INF, pos = source;
 	for(int j = 0; j < size; j++)
 	{
 		if(!visited[j] && dist[j] < min_val)
 		{
 			pos = j;
 			min_val = dist[j];
 		}
 	}

 	visited[pos] = true;
 	for(int j = 0; j < size; j++)
 	{
 		int val = g[pos][j] + dist[pos];
 		if(!visited[j] && dist[j] > val)
 		{
 			dist[j] = val;
 		}
 	}
 }

 display(dist, size);
}

int main()
{
	int v;

	cout<<"Enter the number of edges: ";
	cin>>v;

	cout<<"Enter the graph (adj matrix)\n";
	for(int i = 0; i < v; i++)
	{
		for(int j = 0; j < v; j++)
			{
				cin>>g[i][j];
				if(g[i][j] == 0)
					g[i][j] = INF;
			}
	}

	int source;

	cout<<"Enter the source vertex: ";
	cin>>source;

	dijkstra(source, v);
	return 0;
}