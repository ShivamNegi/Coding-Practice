#include <stdio.h>
#include <stdlib.h>

int *visited;
int **mat;
int v;
int *push;
int *pop;
int push_i = 0, pop_i = 0;

void dfs(int x)
{
	visited[x] = 1;
	printf("%d\n",x);

	int i = 0;
	for(i = 0 ; i < v ; i++)
	{
		if((mat[x][i]==1) && (visited[i]==0))
		{	
			push[push_i] = i;
			push_i++;
			dfs(i);
		}	
	}	
	pop[pop_i] = x;
	pop_i++;
}

void disp()
{
	int i = 0;
	printf("push order\n");
	for(i = 0 ; i < v; i++)
	{
		printf("%d\t",push[i] + 1);
	}
	
	printf("\npop order\n");
	for(i = 0 ; i < v; i++)
	{
		printf("%d\t",pop[i] + 1);
	}
}

void main()
{
	v = 0;
	printf("enter num of vertices\n");
	scanf("%d",&v);
	
	mat = (int **)(malloc(sizeof(int *)*v));
	visited = (int *) (malloc(sizeof(int )*v));
	push = (int *) (malloc(sizeof(int )*v));
	pop = (int *) (malloc(sizeof(int )*v));
	int i = 0, j = 0;
	for( i = 0 ;  i < v ; i++)
	{
		visited[i] = 0;
		int x = -1;
		mat[i] = (int *)(malloc(sizeof(int)*v));
		printf("enter adjacent vertices of vertex %d\nenter -1 to exit\n",i);
		while(1)
		{
			scanf("%d",&x);
			if(x<0){ break; }
			mat[i][x] = 1;
		}		
	}
	
	push[push_i] = 0;
	push_i++;
	dfs(0);
	disp();	
}
