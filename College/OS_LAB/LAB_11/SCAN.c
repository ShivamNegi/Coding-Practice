#include <stdio.h>
#include <stdlib.h>

void sort(int *a, int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int getpos(int a[], int start, int n)
{
	int i = 0;
	for(i; i < n; i++)
	{
		if(a[i] > start)
			return i;
	}
	return n - 1;
}

void display(int a[], int n)
{
	int i = 0;
	for(i; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

int main()
{
	int n;
	printf("Enter the number of tracks: ");
	scanf("%d", &n);
	
	n++;
	int a[n], i = 0;
	
	for(i = 0; i < n - 1; i++)
		scanf("%d", &a[i]);
	
	//adding a zero
	a[n - 1] = 0;
	sort(a, n);
	display(a, n);	
	
	int start, time = 0;
	printf("Enter the start position: ");
	scanf("%d", &start);
	
	int pos = getpos(a, start, n);
	
	//printf("the pos and ele is %d %d \n", pos, a[pos]);
	printf("Tracks Traversed\t\tDifference\n");
	
	time = abs(a[pos - 1] - start);
	printf("%d\t\t%d\n", a[pos - 1], time);
	for(i = pos - 2; i >= 0; i--)
	{
		int val = abs(a[i] - a[i + 1]);
		time += val;
		printf("%d\t\t%d\n", a[i], val);
	}
	
	int out = abs(a[pos]);
	time += out;
	printf("%d\t\t%d\n", a[pos], out);
	for(i = pos + 1; i < n; i++)
	{
		int val = abs(a[i] - a[i - 1]);
		time += val;
		printf("%d\t\t%d\n", a[i], val);
	}
	
	
	printf("The total time: %d\n", time);
	printf("Average seek time: %d\n", time / (n - 1));
	return 0;
}
