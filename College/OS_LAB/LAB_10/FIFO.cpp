#include <stdio.h>

int size, top;
int a[100], stack[100];

void init_stack()
{
	int i = 0;
	for(i; i < size; i++)
		stack[i] = -1;
}

int ispresent(int x)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		if(stack[i] == x)
			return 1;
	}
	return 0;
}

void display(int x)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printf("%d\t", stack[i]);
	}
	printf("PF no: %d\n", x);
}

int main()
{
	int i = 0, counter = 0, flag = 0, n;
	top = 0;
	
	printf("Enter the length of string reference: ");
	scanf("%d", &n);
	
	printf("Enter the reference string: ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	printf("Enter the number of frames: ");
	scanf("%d", &size);
	
	init_stack();
	for(i = 0; i < n; i++)
	{
		if(top == size)
			top = 0;
		if(flag)
		{
			if(!ispresent(a[i]))
			{
				stack[top++] = a[i];
				counter++;
			}			
		}
		else
		{
			stack[top++] = a[i];
			counter++;
			
			if(top == size)
				flag = 1;
		}
		display(counter);
	}
	
	printf("The number of page faults are: %d\n", counter);
	return 0;
}
