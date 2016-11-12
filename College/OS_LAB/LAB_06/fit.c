#include <stdio.h>

void sort(int * a, int * pos, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			if(a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				
				temp = pos[i];
				pos[i] = pos[j];
				pos[j] = temp;
			}
		}
	}
}

void bestfit(int a[], int b[])
{
	int n = sizeof(a) / sizeof(a[0]);
	int pos[n];		
	int i = 0;
	
	for(i = 0; i < n; i++)
		pos[i] = i;
	
	sort(a, pos, n);	
	for(i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		int j = 0, flag = 0;
		for(j = 0; j < n; j++)
		{
			if(a[j] >= b[i])
			{
				flag = 1;
				break;
			}
		}
		
		if(flag)
		{
			printf("File No: %d, File Size: %d, Block No: %d, Block Size: %d, Fragment: %d\n", i + 1, b[i], pos[j] + 1, a[j], a[j] - b[i]);
			a[j] -= b[i]; 
			sort(a, pos, n);	
		}
		else
			printf("Memory couldn't be allocated for %d\n", i + 1);
	}
}

void firstfit(int a[], int b[])
{
	int n = sizeof(a) / sizeof(a[0]);
	int i, j;
	
	for(i = 0; i < sizeof(b) / sizeof(b[0]); i++)
	{
		int flag = 0;
		for(j = 0; j < n; j++)
		{
			if(a[j] >= b[i])
			{
				flag = 1;
				break;
			}
		}
		
		if(flag)
		{
			printf("File No: %d, File Size: %d, Block No: %d, Block Size: %d, Fragment: %d\n", i + 1, b[i], j + 1, a[j], a[j] - b[i]);
			a[j] -= b[i];
		}
		else
			printf("Memory couldn't be allocated for %d\n", i + 1);
	}
}

int main()
{
	int no_block, no_files;
	
	printf("Enter the number of blocks: ");
	scanf("%d", &no_block);
	printf("Enter the number of files: ");
	scanf("%d", &no_files);
	
	int blocks[no_block], i;
	
	printf("Enter the size of the blocks\n");
	for(i = 0; i < no_block; i++)
	{
		printf("Block %d: ", i + 1);
		scanf(" %d", &blocks[i]);
	}
	
	int files[no_files];
	
	printf("Enter the size of files\n");
	for(i = 0; i < no_files; i++)
	{
		printf("File %d: ", i + 1);
		scanf(" %d", &files[i]);
	}
	
	//printf("\tFirst Fit\n");
	//firstfit(blocks, files);
	
	printf("\tBest Fit\n");
	bestfit(blocks, files);
	
	return 0;
}
