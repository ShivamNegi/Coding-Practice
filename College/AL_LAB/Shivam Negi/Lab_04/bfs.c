#include<stdio.h>

int a[20][20],visited[30],q[30],i,j,n,f=0,r=-1;

void bfs(v)
{
 while(f<=r)
 {
  v=q[f];
  for(j=0;j<n;j++)
  {
   if(a[v][j]==1 && visited[j]==0)
   {
    q[++r]=j;
   }
  }
  visited[q[f]]=1;
  printf("%d ",q[f++]);
 }
}

void main()
{
 int v;
 printf("Enter the number of vertices\n");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  q[i]=0;
  visited[i]=0;
 }
 printf("Enter the adjacency matrix\n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 printf("Enter the starting vertex\n");
 scanf("%d",&v);
 q[++r]=v;
 bfs(v);
}
