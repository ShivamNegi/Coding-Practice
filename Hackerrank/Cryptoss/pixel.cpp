#include <bits/stdc++.h>
#define SIZE 1000
// if error ^ -1

using namespace std;

int grid[SIZE][SIZE];

void init()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
            grid[i][j] = 0;
    }
}

void make_grid(vector<int>& a, vector<int>& b, int x, int y)
{
    init();
    for(int i = 0; i < a.size(); i++)
        grid[a[i] + x][b[i] + y] = 1;
}

int main()
{
    int v, n, m;
    cin>>v>>m>>n;   // n X m

    vector<int> a_past, b_past;
    for(int i = 0; i < v; i++)
    {
        int a, b;
        cin>>a>>b;

        a_past.push_back(a);
        b_past.push_back(b);
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            make_grid(a, b, i, j);
            
        }
    }
    return 0;
}