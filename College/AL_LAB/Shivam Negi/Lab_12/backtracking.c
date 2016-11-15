#include <stdlib.h>
#include <stdio.h>

int n ;

int *arr;
int *res;
int k = 0;
int fx(int s, int i, int x)
{
	if(s==0){
		int  k = 0;
		for(k = 0; k < n; k++)
		{
			if((x&(1<<k))!=0)
			{
				printf("%d\t",arr[k]);	
			}
		}
		printf("\n");
		return 1;
	}
	if(i==n){return 0;}
	int t1= 0;
		
	if(s-arr[i]>=0){	
		  res[i] = arr[i];	
		  int y   = x|(1<<i);
		  t1 = fx(s-arr[i],i+1,y );

		  }	
		  
	  
 	fx(s,i+1, x);
	
	if(i == 0)
	{
		printf("\n");
	}
	return t1;

}



int main()
{
	printf("enter num of ele\n");
	scanf("%d",&n);
	
	arr  = (int *)malloc(sizeof(int)*n);
	res =  (int *)malloc(sizeof(int)*n);
	
	int i = 0 , j = 0;
	for(i = 0 ; i < n; i++)
	{	
		scanf("%d",&arr[i]);
		res[i]=0;
	}

	int  d = 0;
	printf("Required sum: ");
	scanf("%d",&d);	
	fx(d,0, 0);
}
