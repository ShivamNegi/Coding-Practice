#include <stdio.h>
#include <stdlib.h>
int count = 0;
void heapify (int a[], int n)
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
      count++;
    }
    a[i] = item;
  }
} 

int main()
{
  int i, n, a[50];
  printf("Enter number of elements\n");
  scanf("%d", &n);
  for (i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
    heapify(a, i+1);
  }
  printf("Heap is\n");
  for (i=0; i<n; i++)
    printf("%d  ", a[i]);
  printf("The Total Operations : %d\n",count);
  return 0;
} 