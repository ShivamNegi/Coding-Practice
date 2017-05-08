#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int n;

 cin>>n;

 int a[100][100];
 int limit = n * n;

 //all zeros
 for(int i = 0; i <= limit; i++)
    {
     for(int j = 0; j <= limit; j++)
        a[i][j] = 0;
    }

 a[(n - 1) / 2][n - 1] = 1;
 int row = (n - 1) / 2, col = n - 1;

 for(int i = 2; i <= limit; i++)
    {
     int nrow, ncol;

     nrow = row - 1;
     ncol = col + 1;

    //check
     if(nrow < 0)
        nrow = n - 1;
     if(ncol > n - 1)
        ncol = 0;

     if(a[nrow][ncol] == 0)
        {
         a[nrow][ncol] = i;
        }
     else
        {
         nrow = row - 2;
         ncol = col;
        }

     if(nrow < -1)
        nrow = n - 2;
     if(nrow < 0)
        nrow = n - 1;
     if(ncol > n - 1)
        ncol = 0;

     if(a[nrow][ncol] == 0)
        {
         a[nrow][ncol] = i;
        }
     row = nrow;
     col = ncol;
    }

 /*for(int i = 0; i <n; i++)
    {
     for(int j = 0; j<n; j++)
        {
         cout<<a[i][j]<<"\t";
        }
     cout<<endl;
    }*/
 cout<<a;
 return 0;
}
