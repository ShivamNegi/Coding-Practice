#include <iostream>
#include <cmath>

using namespace std;

void display(int a[], int size)
{
	for(int i = 0; i < size; i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}

// Iterative
void subset_sum(int a[], int d, int size)
{
	int lim = 1<<size;

	for(int i = 0; i < lim; i++)
	{
		int curr[size], counter = 0, sum = 0;
		for(int j = 1; j < lim;)
		{
			if((i & j) > 0)
			{
				int pos = log(j) / log(2);
				sum += a[pos];
				// storing all the elements along with the calculating the sum
				curr[counter++] = a[pos];
			}
			j = j<<1;
		}
		if(sum == d)
			display(curr, counter);
	}
}

int main()
{
	int n;

	cout<<"Enter the number of elements: ";
	cin>>n;

	int a[n];

	cout<<"Enter the elemets: ";
	for(int i = 0; i < n; i++)
		cin>>a[i];

	int d;

	cout<<"Enter the sum to obtain: ";
	cin>>d;

	subset_sum(a, d, n);

	return 0;
}