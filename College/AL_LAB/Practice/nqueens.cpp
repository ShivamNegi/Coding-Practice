#include <iostream>
#define SIZE 10

using namespace std;

int a[SIZE][SIZE];

void init(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			a[i][j] = -1;
	}
}

bool check(int x, int y, int n)
{
	// horizontal check and vertical check
	for(int i = 0; i < n; i++)
	{
		if(a[x][i] == 1 && i != y)
			return false;
		if(a[i][y] == 1 && i != x)
			return false;
	}

	// diagonal check
	// decreasing
	for(int i = x - 1, j = y - 1; i >= 0 || j >= 0; i--, j--)
	{
		if(a[i][j] == 1)
			return false;
	}

	for(int i = x + 1, j = y - 1; j >= 0 || i < n; i++, j--)
	{
		if(a[i][j] == 1)
			return false;
	}

	for(int i = x - 1, j = y + 1; i >= 0 || j < n; i--, j++)
	{
		if(a[i][j] == 1)
			return false;
	}

	for(int i = x + 1, j = y + 1; i < n || j < n; i++, j++)
	{
		if(a[i][j] == 1)
			return false;
	}

	return true;
}

void display(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}
}

void nqueens(int n, int placed)
{
	if(placed == n)
	{
		display(n);
		cout<<endl;
	}
	for(int i = 0; i < n; i++)
	{
		if(check(placed, i, n))
		{
			a[placed][i] = 1;
			nqueens(n, placed + 1);
			a[placed][i] = -1;
		}
	}
	return;
}

int main()
{
	int n;

	cout<<"Enter the number of queens: ";
	cin>>n;

	init(n);
	nqueens(n, 0);

	return 0;
}