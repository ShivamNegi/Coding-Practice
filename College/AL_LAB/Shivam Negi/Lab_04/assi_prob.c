#include <stdio.h>
#include <stdlib.h>

int **out, total_jobs, n_person, ans = 10000, *jdb, counter = 0;

void assign(int i, int jd , int cost, int arr[])
{
	int j;
	if(i == total_jobs)
	{
			counter++;
			if(ans>cost)
			{
				ans = cost;
				jdb = arr;
			}			
			return ;
	}	
	for(j = 0 ; j < total_jobs; j++)
	{
		int val = (1<<j);
		if(val & jd == 0)
		{
			arr[j] = i;
			int c = cost + out[i][j];
			assign(i+1, val | jd, c, arr);
		}
	}
}


void display()
{
	printf("cost = %d\nset = \n",ans);
	int j = 0;

	for(j = 0 ; j < total_jobs; j++)
		printf("person %d: %d\n",j,jdb[j]);
}

int main()
{ 
 printf("jobs: ");
 scanf("%d",&total_jobs);
 printf("people: ");
 scanf("%d",&n_person);
 
 int x1 = total_jobs, x2 = n_person;
 int arr[x2];
 
 jdb = (int *)(malloc(sizeof(int)*x1)); 
 out = (int **)(malloc (sizeof(int *)*x2));
 
 int i = 0, j = 0; 
 for(i = 0 ; i  < x2; i++)
 {
 	out[i] = (int *)(malloc(sizeof(int)*x1));
 	printf("enter jobs for person %d\n",i);
 	for(j = 0 ; j < x1 ; j++)
 	{
 		scanf("%d",&out[i][j]);
 	}
 }
 
 int z = 99999999 ;
 int *p = &z;
 
 assign(0,0,0,arr);
 display();
 printf("\nthe number of basic operations are: %d\n", counter);
 return 0;
}
