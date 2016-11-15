#include <stdlib.h>
#include <stdio.h>

int *wt;
int *val;
int n;

int knapsack_b(int cap, int x)
{

if(cap<0){return 0;}
if((cap==0)||(x==n))
	return 0;	
	
	int t1 = 0, t2 = 0;
	if(cap-wt[x]>=0)
	 t1 = knapsack_b(cap-wt[x],x+1)+val[x];
	 t2 = knapsack_b(cap,x+1);

	if(t1>t2)
	{
		return t1;
	}
	
	
	
	return t2;
}



int main()
{
	int cap;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter value, weight: ");
	wt = (int *)(malloc(sizeof(int)*n));
	val = (int *)(malloc(sizeof(int)*n));
	
	int i = 0, j = 0;
	for(i = 0 ; i < n; i++)
	{
		scanf("%d",&val[i]);
		scanf("%d",&wt[i]);
	}
	
	printf("enter cap\n");
	scanf("%d",&cap);
    int res = 	knapsack_b(cap,0);
    printf("the result of the knapsack is: %d\n",res);	 
 
	return 0;
 
}

