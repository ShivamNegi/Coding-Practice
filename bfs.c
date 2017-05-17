#include <stdio.h>

using namespace std;

int main()
{
  int no_nodes;

  printf("Enter the number of nodes: ");
  scanf("%d", &no_nodes);

  int graph[no_nodes][no_nodes];

  for(i = 0; i < no_nodes; i++)
    {
      for(j = 0; j < no_nodes; j++)
	printf("%d\t", graph[i][j]);
      printf("\n");
    }

  return 0;
}
