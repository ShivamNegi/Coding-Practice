#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int counter = 0, n, m;
char a[500][500];

void frombottom(int x, int y, int x1, int y1);

void fromtop(int x, int y, int x1, int y1)
{
    if(x == x1 && y == y1)
    {
        counter = counter % MOD;
        counter++;
        return;
    }
    if(a[x][y] == a[x1][y1])
    {
        if(x < n)
            frombottom(x + 1, y, x1, y1);
        else
            return;
        if(x < m)
            frombottom(x, y + 1, x1, y1);
        else
            return;
    }
    else
        return;
}

void frombottom(int x, int y, int x1, int y1)
{
    if(x1 > 0)
        fromtop(x, y, x1 - 1, y1);
    else
        return;
    if(y1 > 0)
        fromtop(x, y, x1, y1 - 1);
    else
        return;
}

int main()
{
    cin>>n>>m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }

    fromtop(0, 0, n - 1, m - 1);

    cout<<counter<<endl;
    return 0;
}