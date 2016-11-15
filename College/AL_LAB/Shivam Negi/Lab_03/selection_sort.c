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

 // selection sort
 int pos = 0, min = a[0], j = 0;
 for(i = 0; i < len; i++)
	{
		pos = i;
		min = a[pos];
		for(j = i + 1; j < len; j++)
			{
				if(a[j] < min)
					{
						min = a[j];
						pos = j;	
					}
			}

		int temp = a[pos];
		a[pos] = a[i];
		a[i] = temp;		
	}
 display(a, len);
 return 0;
}
