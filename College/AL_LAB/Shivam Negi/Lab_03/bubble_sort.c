#include <stdio.h>

void display(int a[], int size)
{
 int i = 0;
 for(i; i < size; i++)
	{
		printf("%d ", a[i]);
	}
 printf("\n");
}

int main()
{
 int len;
 scanf(" %d", &len);

 int a[len], i;

 for(i = 0; i < len; i++)
	{
		scanf(" %d", &a[i]);
	}

 // bubble sort
 int j;
 for(i = 0; i < len; i++)
	{
		for(j = 0; j < len - 1- i; j++)
			{
				if(a[j] < a[j + 1])
					{
						int temp = a[j];
						a[j] = a[j + 1];
						a[j + 1] = temp;
					}
			}
	}
 display(a, len);
 return 0;
}
