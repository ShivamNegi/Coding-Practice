#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int i, int j)
{
 int temp = a[i];
 a[i] = a[j];
 a[j] = temp;
}

void display(int * arr, int size)
{
 int i, j;
 
 for(i = 0; i < size;i ++)
	{
	 printf("%d ", arr[i]);
	}
 printf("\n");
}


void permutation(int * arr, int size, int pos)
{
 if(size == pos)
	 display(arr, size);
	 //insert(arr, size);	
 else
	{
 	 int i = pos + 1;
	 for(i; i < size; i++)
		{
			swap(arr, pos, i);
			permutation(arr, size, pos + 1);
			swap(arr, pos, i);
		}
	}
}


int main()
{
 int x;
 scanf(" %d", &x);
 int i;

 int * a = (int *) malloc(sizeof(int)); 
 for(i = 0; i < x; i++)
	{
	 scanf(" %d", &a[i]);
	}
 permutation(a, x, 0);
}
