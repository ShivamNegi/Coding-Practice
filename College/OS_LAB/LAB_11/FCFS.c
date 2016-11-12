#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	printf("Enter the number of tracks: ");
	scanf("%d", &n);
	
	int a[n], i = 0, cum_sub[n];
	
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int start, time = 0;
	printf("Enter the start position: ");
	scanf("%d", &start);
	
	printf("Tracks Traversed\t\tDifference\n");
	cum_sub[0] = abs(a[0] - start);
	printf("%d\t\t%d\n", a[0], cum_sub[0]);
	for(i = 1; i < n; i++)
	{
		cum_sub[i] = abs(a[i] - a[i - 1]);
		printf("%d\t\t%d\n", a[i], cum_sub[i]);
	}
		
	
	for(i = 0; i < n; i++)
		time += cum_sub[i];

	printf("The total time: %d\n", time);
	printf("Average seek time: %d\n", time / n);
	return 0;
}
