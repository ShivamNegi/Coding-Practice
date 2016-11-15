#include<stdio.h>
int n;int count=0;
void sort(int a[])
{
	int i,j;
	int s[15],c[100];
	for(i=0;i<=n-1;i++) c[i]=0;
	for(i=0;i<=n-2;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{   count++;
			if(a[i]<a[j]){ c[j]=c[j]+1; } else c[i]=c[i]+1;
		}
	}
	for(i=0;i<=n-1;i++) s[c[i]]=a[i];
	printf("The sorted array is : \n");
	for(i=0;i<=n-1;i++) printf("%d\t",s[i]);	
	printf("\nThe count: %d \n",count);
}
int main()
{
	int k=0,a[15],i;
	printf("Enter the number of integers\n");
	scanf("%d",&n);
	printf("Enter the integers to be sorted \n");
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a);
	printf("\n");
}
