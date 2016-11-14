#include <iostream>


using namespace std;

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// bottom up heap creation
void heapify(int arr[], int size)
{
	for(int i = size / 2; i > 0; i--)
	{
		int k = i, val = arr[i];
		bool heap = false;

		for(; 2 * k <= size && !heap;)
		{
			int j = 2 * k;
			// this means there are two children
			if(j < size)
				if(arr[j] < arr[j + 1])
					j = j + 1;
			if(arr[j] > val)
			{
				arr[k] = arr[j];
				k = j;
			}
			else
				heap = true;
		}
		arr[k] = val;
	}
}

void display(int arr[], int size)
{
	cout<<endl;
	for(int i = 1; i < size; i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

int main()
{
	int n;

	cout<<"Enter the number of elements: ";
	cin>>n;

	int arr[++n];

	cout<<"Enter the elements: ";
	for(int i = 1; i < n; i++)
		cin>>arr[i];

	display(arr, n);
	heapify(arr, n-1);
	display(arr, n);
	return 0;
}