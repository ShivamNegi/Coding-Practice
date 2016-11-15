#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int size = 0;

void display(int a[][size])
{
 int i = 0, j; 

 for(i; i < size; i++)
	{
		for(j = 0; j < size; j++)
			printf("%d  ", a[i][j]);
		printf("\n");
	}
}

int main()
{
 printf("How many edges? ");
 scanf(" %d", &size);

 int a[size][size];

 while(true)
	{
		int x, y;
		printf("Keep adding edges x, y\n");
		scanf(" %d %d", &x, &y);

		a[x][y] = 1;
		a[y][x] = 1;

		char ch;
		printf("do you want to keep inserting? (y/n) ");
		scanf(" %c", &ch);
		if(ch == 'n')
			break;
	} 
 display(a);

 return 0;
}
