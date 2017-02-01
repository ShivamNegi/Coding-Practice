#include <iostream>

using namespace std;

int ZigZagCount(int a[], int n, bool flag)
{
	
}

int main()
{
	int n;
	cin>>n;

	int a[n];

	for(int i = 0; i < n; i++)
		cin>>a[i];

	cout<<ZigZagCount(a, n, false);

	return 0;
}
