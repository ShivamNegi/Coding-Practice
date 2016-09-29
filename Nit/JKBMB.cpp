#include <bits/stdc++.h>

using namespace std;

int counter = -1;
int r, c;

void display(vector< vector<int> > a)
{
    for(int i = 0; i < a.size(); i++)
    {
        for(int j = 0; j < a[i].size(); j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void color_neig(vector< vector<int> > &a, int i, int j)
{
    a[i][j] = counter;

    if(i - 1 >= 0 && a[i - 1][j] == 0)        color_neig(a, i - 1, j);

    if(i + 1 < r && a[i + 1][j] == 0)        color_neig(a, i + 1, j);

    if(j - 1 >= 0 && a[i][j - 1] == 0)        color_neig(a, i, j - 1);

    if(j + 1 < c && a[i][j + 1] == 0)        color_neig(a, i, j + 1);
}

int main()
{
    cin>>r>>c;

    vector< vector<int> > inp;

    for(int i = 0; i < r; i++)
    {
        vector<int> row;
        for(int j = 0; j < c; j++)
        {
            int no;
            cin>>no;
            row.push_back(no);
        }
        inp.push_back(row);
    }

    //display(inp);
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(inp[i][j] == 0)
                {
                    color_neig(inp, i, j);
                    counter--;
                }
        }
    }

    display(inp);
    return 0;
}