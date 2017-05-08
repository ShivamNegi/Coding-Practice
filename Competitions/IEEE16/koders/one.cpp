#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int n;
 cin>>n;

 int a[100][100];

 int limit = n * n + 1;

 //make all zeros
 for(int i = 0; i < limit; i++)
    {
     for(int j = 0; j < limit; j++)
        {a[i][j] = 0;}
    }

 int row, col;

 row = (n - 1) / 2;
 col = n - 1;
 a[row][col] = 1;

 for(int i = 2; i < limit; i++)
    {
     int nrow, ncol;

     nrow = row - 1;
     ncol = col + 1;

     if(nrow < 0)
        nrow = n - 1;
     if(ncol > n - 1)
        ncol = 0;

     if(a[nrow][ncol] == 0)
        a[nrow][ncol] = i;
     else
        nrow = row - 2;

     if(nrow < -1)
        nrow = n - 2;
     if(nrow < 0)
        nrow = n - 1;
     if(ncol > n - 1)
        ncol = 0;

     if(a[nrow][ncol] == 0)
        a[nrow][ncol] = i;

     row = nrow;
     col = ncol;
    }

 for(int i = 0; i < n; i++)
    {
     for(int j = 0; j < n; j++)
        cout<<a[i][j]<<"\t";
     cout<<endl;
    }

 return 0;
}
