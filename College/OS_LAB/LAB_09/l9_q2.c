#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c = 0;
	int n;
	int r;
	printf("enter num of proc & num of res\n");
	scanf("%d%d",&n , &r);
	int mat[n+1][r+1];
	int max[n+1][r+1];
	int exe[n+1];
	int av[r+1];
	int i = 0;
	int j = 0 ; 
	for(i = 0 ; i < n ; i++)
	{	
		exe[i] = 0;
		printf("P%d\n",i);
		printf("enter allocation%d\n",i);
		for(j  = 0 ; j < r; j++)
			scanf("%d",&mat[i][j]);

		printf("enter max%d\n",i);
		for(j  = 0 ; j < r; j++)
			scanf("%d",&max[i][j]);
	
	}
	
	
	printf("enter available\n");
	for(j  = 0 ; j < r; j++)
		scanf("%d",&av[j]);
	
	
	for( i = 0; c<n ;i++ )
	{
		int f = 0;

		if(exe[i]==1){continue;}

		for(j = 0 ; j <r; j++)
			if(max[i][j]-mat[i][j]>av[j])
				f = 1;		

		if(f==0)
		{
			exe[i] = 1;

			for(j  = 0 ; j < r; j++)
				av[j] += mat[i][j];

			printf("P%d\n",i);

			c++;
			if(c==n)
				break;

			i = -1;
		}
		if(i>=n)
		{
			printf("NOT POSSIBLE\n");
			break;
		}
	
	}
	
	return 0;
	
	

}
