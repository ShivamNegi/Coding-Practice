#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define SIZE 100
#define INF 10e7

using namespace std;

int g[SIZE][SIZE];

void display(int a[], int size)
{
	for(int i = 1; i < size; i++)
	{
		if(a[i] == INF)
			cout<<"-1 ";
		else
			cout<<a[i]<<" ";
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
 for(int i = 0; i < size; i++)
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

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    
    while(t--)
    {
        int v, e;
        
        cin>>v>>e;
        
        for(int i = 0; i < v; i++)
            for(int j = 0; j < v; j++)
                g[i][j] = INF;
        
        for(int i = 0; i < e; i++)
            {
            int x, y, r;
            cin>>x>>y>>r;
            x--;y--;
            g[x][y] = r;
            g[y][x] = r;
        }
        int source;
        cin>>source;
        dijkstra(source - 1, v);
    }
    return 0;
}
