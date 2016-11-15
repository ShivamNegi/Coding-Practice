#include<stdio.h>

int counter = 0;
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1), j;
 
    for (j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
          	counter++;
            i++;  
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
 
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
	
	printf("Enter the size of the array: ");
	scanf(" %d", &n);
	
	int i = 0;
    int arr[n];
	for(i; i < n; i++)
		{
			scanf(" %d", &arr[i]);
		}
		
    quickSort(arr, 0, n-1);
    printf("Sorted array: \n");
    printArray(arr, n);
    printf("The number of operations is %d\n", counter);
    return 0;
}
