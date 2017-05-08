#include <iostream>

using namespace std;

long long arr[2000][2000];
long long r, c;
bool visited[2000][2000];

long long fx(int x, int y)
{
	if(visited[x][y])
		{ return 0; }

	visited[x][y] = true;
	long long res = arr[x][y];
	if (arr[x][y] == 0)
	{		
		if ((x - 1 >= 0) && !(visited[x - 1][y])) { res = res + fx(x - 1, y); }
		if ((x + 1 < r) && !(visited[x + 1][y])) { res = res + fx(x + 1, y); }
		if ((y - 1 >= 0) && !(visited[x][y - 1])) { res = res + fx(x, y - 1); }
		if ((y + 1 < c) && !(visited[x][y + 1])) { res = res + fx(x, y + 1); }
	}	
	return res;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin>>r;
	cin>>c;
	long long sum = 0;


	for (long long i = 0; i < r; i++)
	{
		for (long long j = 0; j < c; j++)
		{
			cin>>arr[i][j];
			sum = sum + arr[i][j];
			visited[i][j] = false;
		}
	}

	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin>>x>>y;

		if(arr[x][y] != 0)
			{
				cout<<sum<<endl;
				continue;
			}

		long long res = fx(x, y);
		sum = sum - res;
		cout<<sum<<endl;
	}
	return 0;
}
