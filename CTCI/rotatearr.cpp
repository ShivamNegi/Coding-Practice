#include <iostream>

using namespace std;

int main()
{
 int n;
 cin>>n;
 
 int a[n][n], b[n][n];

 for(int i = 0; i < n; i++)
	{
	 for(int j = 0; j < n; j++)
		{
		 cin>>b[i][j];
		}
	}

 for(int i = 0; i < n; i++)
	{
	 for(int j = 0; j < n; j++)
		{
		 a[n - 1 -j][i] = b[i][j];
		}
	}

 for(int i = 0; i < n; i++)
	{
	 for(int j = 0; j < n; j++)
		{
		 cout<<a[i][j]<<"  ";
		}
	cout<<endl;
	}

 return 0;
}
