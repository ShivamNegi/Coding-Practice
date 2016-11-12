#include <stdio.h>

int main()
{
	int mem, par;
	
	printf("Enter the total memory available: ");
	scanf("%d", &mem);
	
	printf("Enter the partition size: ");
	scanf("%d", &par);
	
	int counter, tot;
	tot = mem / par;
	counter = 1;
	
	int allocated, fragmented;
	allocated = fragmented = 0; 
	while(1)	
	{
		char ch;
		int p;
		printf("Enter memory required for process %d: ", counter);
		scanf(" %d", &p);
		printf("Allocate memory? (y/n): ");
		scanf(" %s", &ch);
		
		if(counter > tot)
		{
			printf("The memory is full\n");
			break;
		}		
		if(ch == 'y')
		{
			if(p > par)
				continue;
			counter++;
			allocated += p;
			fragmented += (par - p);
		}
	}
	
	printf("Total memory allocated is %d an external fragmentation is %d.\n", allocated, fragmented);
	
	return 0;
}
