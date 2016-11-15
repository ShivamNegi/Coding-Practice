#include <stdio.h>
#include <stdlib.h>

int ** mat;
int * visited, * pop, * push;
int pop_i, push_i;

void initialize(int v)
{
 visited = (int *) malloc(sizeof(int) * v);
 mat = (int **) malloc(sizeof(int *) * v);
 pop = (int *) malloc(sizeof(int) * v);
 push = (int *) malloc(sizeof(int) * v);
 pop_i = push_i = 0;
}

void dfs(int x, int v)
{
 visited[x] = 1;
 int i = 0;
 
 for(i; i < v; i++)
 	{
 	 if(mat[x][i] == 1 && visited[i] == 0)
 		{
 		push[push_i ++] = i; 			 			
 		dfs(i, v);
 		}
 	}
 pop[pop_i++] = x;
}
 
void display()
{
  int i = pop_i - 1;
  
  for(i; i >= 0; i--)
  	printf("%d\t", pop[i]);
  printf("\n");
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
	
 int x;
 printf("Enter vertex to start dfs from: ");
 scanf(" %d", &x);
 push[push_i++] = x;
 dfs(x, v);
 display();
 
 return 0;
}
