#include <iostream>

using namespace std;

void init_arr(int a[], int size)
{
	for(int i = 1; i < size; i++)
		a[i] = -1;
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void top_down_heapify(int a[], int pos)
{
 for(int i = pos / 2; i > 0;)
 {
 	int j = i * 2;
 	if(a[j] < a[j + 1])
 		j = j + 1;
 	if(a[j] > a[i])
	{
		swap(&a[j], &a[i]);
		i /= 2;
	}
	else
		break;
 }
}

void heapify(int a[], int size)
{
	for(int i = size / 2; i > 0; i--)
	{
		int k = i, val = a[k];
		bool heap = false;

		for(; 2 * k <= size && !heap; k++)
		{
			int j = 2 * k;
			// This means there are two children of the node
			if(2 * k < size)
				if(a[j] < a[j + 1])
					j = j + 1;
			if(a[j] > a[k])
			{
				a[k] = a[j];
				k = j;
			}
			else
				heap = true;
		}
		a[k] = val;
	}
}

void display(int a[], int size)
{
	cout<<endl;
	for(int i = 1; i < size; i++)
		cout<<i<<"\t";
	cout<<endl;
	for(int i = 1; i < size; i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}

void heapsort(int a[], int n)
{
	for(int j = n; j > 0; j--)
	{
		swap(&a[1], &a[n]);
		n--;
		heapify(a, n);
	}
}

int main()
{
	int n;

	cout<<"Enter the number of elements: ";
	cin>>n;

	int a[++n];

	init_arr(a, n);

	cout<<"Enter the elements: ";
	for(int i = 1; i < n; i++)
	{
		cin>>a[i];
		top_down_heapify(a, i);
	}

	display(a, n);
	heapsort(a, n - 1);
	display(a, n);

	return 0;
}