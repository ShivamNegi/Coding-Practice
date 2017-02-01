#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

void display(int a[], int size)
{
	for(int i = 0; i < size; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int n, p;
	cin>>n>>p;

	int a[n];
	for(int i = 0; i < n; i++)
		cin>>a[i];

	sort(a, a + n);
	
	int val[n];
	for(int i = 0; i < n; i++)
		val[i] = -1;

	for(int i = 0; i < n; i++)
		val[i] = ceil(float(a[i]) / p);

	int ref = 0, counter = val[0] + 1;
	for(int i = 1; i < n; i++)
	{
		if(val[i] - val[ref] <= counter)
		{
			val[i] = counter++;
		}
		else
		{
			ref = i;
			counter = val[ref] + 1;
		}
	}

	//display(val, n);
	cout<<accumulate(val, val + n, 0)<<endl;
	return 0;
}