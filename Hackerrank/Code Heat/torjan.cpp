#include<iostream>
#include <list>
#include <stack>
#define NIL -1

using namespace std;
 
int counter = 0;

class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
 
    // A Recursive DFS based function used by SCC()
    void SCCUtil(int u, int disc[], int low[],
                 stack<int> *st, bool stackMember[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // function to add an edge to graph
    void SCC();    // prints strongly connected components
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
void Graph::SCCUtil(int u, int disc[], int low[], stack<int> *st,
                    bool stackMember[])
{
    static int time = 0;
    disc[u] = low[u] = ++time;
    st->push(u);
    stackMember[u] = true;
    list<int>::iterator i;
    for (i = adj[u].begin(); i != adj[u].end(); ++i)
    {
        int v = *i;  // v is current adjacent of 'u'
 
        // If v is not visited yet, then recur for it
        if (disc[v] == -1)
        {
            SCCUtil(v, disc, low, st, stackMember);
            low[u]  = min(low[u], low[v]);
        }
        else if (stackMember[v] == true)
            low[u]  = min(low[u], disc[v]);
    }
 
    // head node found, pop the stack and print an SCC
    int w = 0;  // To store stack extracted vertices
    int count = 0;
    if (low[u] == disc[u])
    {
        while (st->top() != u)
        {
            w = (int) st->top();
            /*cout << w << " ";*/
            count++;
            stackMember[w] = false;
            st->pop();
        }
        w = (int) st->top();
        count++;
        stackMember[w] = false;
        st->pop();
    }
    if(count > 1)
        counter += count;
}
 
// The function to do DFS traversal. It uses SCCUtil()
void Graph::SCC()
{
    int *disc = new int[V];
    int *low = new int[V];
    bool *stackMember = new bool[V];
    stack<int> *st = new stack<int>();
 
    // Initialize disc and low, and stackMember arrays
    for (int i = 0; i < V; i++)
    {
        disc[i] = NIL;
        low[i] = NIL;
        stackMember[i] = false;
    }
 
    // Call the recursive helper function to find strongly
    // connected components in DFS tree with vertex 'i'
    for (int i = 0; i < V; i++)
        if (disc[i] == NIL)
            SCCUtil(i, disc, low, st, stackMember);
}

void Graph::DFSUtil(int v, bool visited[])
{
    // Mark the current node as visited and print it
    visited[v] = true;
    cout << v << " ";
 
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);
}
 
// DFS traversal of the vertices reachable from v. It uses recursive DFSUtil()
void Graph::DFS(int v)
{
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print DFS traversal
    DFSUtil(v, visited);
}
 
// Driver program to test above function
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        Graph g(n);    
        int a[n][n];

        for(int i = 0; i < n; i++)
        {
            string inp;
            cin>>inp;

            for(int j = 0; j < n; j++)
            {
                if(inp[j] == '1')
                    {                        
                        g.addEdge(i, j);
                    }
            }
        }

        g.SCC();
        cout<<counter<<endl;
        counter = 0;
    } 
    return 0;
}