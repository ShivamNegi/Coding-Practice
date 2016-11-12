#include <stdio.h>

int main()
{
	int mem, par, no_p;
	
	printf("Enter the total memory available: ");
	scanf("%d", &mem);
	
	printf("Enter the block size: ");
	scanf("%d", &par);
	
	printf("Enter the number of processes: ");
	scanf("%d", &no_p);
	
	int tot, counter = 0;
	tot = mem / par;
	
	int allocated, fragmented, k = 0;
	allocated = fragmented = 0; 
	while(k != no_p)	
	{
		int p;
		printf("Enter memory required for process %d: ", k + 1);
		scanf(" %d", &p);
		
		if(counter >= tot)
		{
			printf("The memory is full\n");
		}		
		else
		{
			if(p <= par)
			{
				counter++;
				allocated += p;
				fragmented += (par - p);
				printf("Allocated: %d, Fragmented: %d\n", p, par - p);
			}	
			else
			{
				printf("Greater than block size.\n");
			}		
		}
		
		k++;
	}	
	
	printf("Total internal fragmentation is %d an internal fragmentation is %d.\n", (mem % par), fragmented);
	
	return 0;
}
