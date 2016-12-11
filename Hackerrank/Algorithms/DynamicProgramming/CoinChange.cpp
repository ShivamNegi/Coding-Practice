#include <bits/stdc++.h>

using namespace std;

/*long long counter = 0;*/

/*void display(vector<long long> a)
{
	for(long long i = 0; i < a.size(); i++)
	{
		cout<<a[i]<<"\t";
	}
	cout<<endl;
}

// This only if I want to display all the sets, But I don't have to
void coinchange(long long n, vector<long long>& a, vector<long long> nos, long long pos)
{
	long long val = accumulate(nos.begin(), nos.end(), 0);
	if(val > n)
		return;
	else if(val == n)
	{
		//display(nos);
		counter++;
		return;
	}
	else
	{
		for(long long i = pos; i < a.size(); i++)
		{
			nos.push_back(a[i]);
			coinchange(n, a, nos, i);
			nos.pop_back();
		}
	}
}
*/

long long table[1000][1000];

void init()
{
	for(long long i = 0; i < 1000; i ++)
	{
		for(long long j = 0; j < 1000; j++)
			table[i][j] = -1;
	}
}

long long coinchange(long long n, vector<long long>& a, long long pos)
{
	if(n == 0)
		return 1;
	else if(pos < 0 || n < 0)
		return 0;
	else
	{
		if(table[n][pos] != -1)
			return table[n][pos];
		table[n][pos] = coinchange(n, a, pos - 1) + coinchange(n - a[pos], a, pos);
		return table[n][pos];
	}
		
}

int main()
{
	long long n, m;
	vector<long long> a;
	cin>>n>>m;

	for(long long i = 0; i < m; i++)
	{
		long long no;
		cin>>no;
		a.push_back(no);
	}

	init();

	cout<<coinchange(n, a, a.size() - 1)<<endl;
	return 0;
}