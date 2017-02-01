#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		bool flag = true;
		int n, m;
		cin>>n>>m;

		string inp[n];
		for(int i = 0; i < n; i++)
		{
			cin>>inp[i];
		}

		for(int i = 0; i < n; i++)
		{
			if(inp[i][0] == 'B' && inp[i][m - 1] == 'B')
			{
				continue;
			}
			else
			{
				flag = false;
				break;
			}
		}

		if(!flag)
		{
			cout<<"no\n";
			continue;
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 1; j < m - 1; j++)
			{
				if(inp[i][j] == 'B')
				{
					if(i + 1 < n)
					{
						if(inp[i + 1][j] == 'A')
						{
							flag = false;
							break;							
						}
					}
				}
				else if(inp[i][j] == 'W')
				{
					if(i + 1 < n)
					{
						if(inp[i + 1][j] == 'A')
						{
							flag = false;
							break;
						}
					}					
					if(j + 1 < m)
					{
						if(inp[i][j + 1] == 'A')
						{
							flag = false;
							break;
						}							
					}
					if(j - 1 > -1)
					{
						if(inp[i][j - 1] == 'A')
						{
							flag = false;
							break;							
						}
					}
				}
			}
		}
		if(flag)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
	return 0;
}