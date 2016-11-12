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

void display(int a[], int n)
{
	int i = 0;
	for(i; i < n; i++)
		printf("%d  ", a[i]);
	printf("\n");
}

void update(int * a, int n, int val)
{
	int i;
	for(i = 0; i < n; i++)
		a[i] += val;
}

int main()
{
	int n;
	printf("Enter the number of tracks: ");
	scanf("%d", &n);
	
	int a[n], i = 0;
	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	sort(a, n);
	display(a, n);	
	
	int start, time = 0;
	printf("Enter the start position: ");
	scanf("%d", &start);
	
	// subdividing halfs
	int left[n], right[n], dist_left[n], dist_right[n];
	int l, r;
	l = r = 0;
	
	for(i = 0; i < n; i++)
	{
		if(a[i] < start)
			{
				left[l] = a[i];
				dist_left[l] = abs(left[l] - start);
				l++;
			}
		else
			{
				right[r] = a[i];
				dist_right[r] = abs(right[r] - start);
				r++;
			}
	}
	
	//display(right, r);
	//display(left, l);
	display(dist_right, r);
	display(dist_left, l);
	// getting the closest
	// left array mein sab ulta hai
	printf("Tracks Traversed\t\tDifference\n");
	int counter = 0, il, ir;
	ir = 0;
	il = l - 1;
	while(counter != n)
	{
		if(dist_right[ir] < dist_left[il] || il < 0)
		{
			//printf("right\n");
			int val = dist_right[ir];
			printf("%d\t\t%d\n", right[ir], val);
			ir++;
			update(dist_right, r, -val);
			update(dist_left, l, val);
			time += val;
		}
		else
		{
			//printf("left\n");
			int val = dist_left[il];
			printf("%d\t\t%d\n", left[il], val);
			il--;
			update(dist_right, r, val);
			update(dist_left, l, -val);
			time += val;
		}
		//printf("%d %d\n", ir, il);
		counter++;
	}

	printf("The total time: %d\n", time);
	printf("Average seek time: %d\n", time / n);
	return 0;
}
