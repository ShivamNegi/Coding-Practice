#include <stdio.h>
#include <stdlib.h>

int ** mat;
int * arr, * visited;
int counter;

void initialize(int v)
{
 visited = (int *) malloc(sizeof(int) * v);
 arr = (int *) malloc(sizeof(int) * v);
 mat = (int **) malloc(sizeof(int *) * v);
 counter = 0;
}

void make_zero(int x, int v)
{
 int i;
 visited[x] = 1;
 for(i = 0; i < v; i++)
 	 mat[x][i] = mat[i][x] = 0;
}

void source_removal(int v)
{
 int i = 0, j = 0, count = 0;
 while(count != v)
 	{
 	 for(i = 0; i < v; i++)
 		{
 		 if(visited[j] == 1)
 		 	break;
 		 if(mat[i][j] != 0) 	 
 		 	break;
 		}
 	 if(i == v)
 	 	{
 	 		make_zero(j, v);
 	 		arr[counter++] = j;
 	 		count++;
 	 		j = 0;
 	 	}
 	 else
 	 	j++;
 	}	 
}

void display()
{
 int i = 0;
 for(i; i < counter; i++)
 	{
 		if(i != counter -1)
	 		printf("%d->", arr[i]);
	 	else
	 		printf("%d\n", arr[i]);
 	} 
}

int main()
{
 int v;
 printf("Enter the number of vertices: ");
 scanf("%d", &v);

 initialize(v);
 int i = 0;

 for(i; i < v; i++)
	{
	 visited[i] = 0;
	 mat[i] = (int *) malloc(sizeof(int) * v); 	 
	 
	 printf("Enter the vertices for %d.", i);
	 printf("Enter -1 if you wish to exit.\n");

	 int x;
	 scanf("%d", &x);
	 while(1)
	 	{	
			if(x < 0)
				break;
			mat[i][x] = 1;
			scanf("%d", &x);
		}
	}
 source_removal(v);
 display();
 return 0;
}	
