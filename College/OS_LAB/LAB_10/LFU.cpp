#include <stdio.h>

int size, top;
int a[100], stack[100], out[100];

void init_stack()
{
	int i = 0;
	for(i; i < size; i++)
		{
			stack[i] = -1;
			out[i] = 0;
		}
}

int ispresent(int x)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		if(stack[i] == x)
			return i;
	}
	return -1;
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

void displayout(int x)
{
	int i = 0;
	for(i = 0; i < size; i++)
	{
		printf("%d\t", out[i]);
	}
	printf("PF no: %d\n", x);
}

int min_freq()
{
	int i, min = out[0], min_pos = 0;
	for(i = 1; i < size; i++)
	{
		if(min > out[i])
		{
			min = out[i];
			min_pos = i;
		}
	}
	return min_pos;
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
			int pos = ispresent(a[i]);
			if(pos == -1)
			{
				//printf("present\n");
				int req_pos = min_freq();
				stack[req_pos] = a[i];
				out[req_pos] = 0;
				counter++;
			}
			else
			{
				out[pos]++;
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
