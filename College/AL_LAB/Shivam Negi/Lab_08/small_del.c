#include<stdio.h>
#include<stdlib.h>

int min(int *a,int n)
{
		int smallest = 0,i;
		for(i=1;i<n;i++)
			if(a[smallest]>a[i])
				smallest = i;
	return smallest;
}

void heapify(int *a,int n)
{
  int k, i, j, item;
  for (k=1; k<n; k++)
  {
    item = a[k];
    i = k;
    j = (i-1)/2;
    while ((i>0) && (item>a[j]))
    {
      a[i] = a[j];
      i = j;
      j = (i-1)/2;
    }
    a[i] = item;
  }
}

void main()
{
		int *a,n,i;
		printf("Enter the number of elements\n");
		scanf("%d",&n);
		a = (int*)calloc(n,sizeof(int));
		printf("Enter the elements\n");
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		int pos = min(a,n);
		int temp = a[n-1];
		a[n-1] = a[pos];
		a[pos] = temp;

		heapify(a,n-1);
		printf("Heap is :");
		for(i=0;i<n-1;i++)
				printf("%d ",a[i]);
}
