#include<stdio.h>

int p[100][100],n,np;

void main()
{
	int i,j,tot,size,l,x,pn,pg,of;
	
	printf("Enter Memory Size:");
	scanf("%d",&tot);
	
	printf("Enter Page size:");
	scanf("%d",&size);
	
	n=tot/size;
	
	printf("Enter no.of processes:");
	scanf("%d",&np);
	
	x=n;
	for(i=0;i<np;i++)
	{
		printf("\nEnter the no of pages in P%d: ",i+1);
		scanf("%d",&l);
		
		x=x-l;
		printf("\n%d\n",x);
		
		if(x>=0)
			for(j=0;j<l;j++)
				scanf("%d",&p[i][j]);
		else
			break;
	}
	if(x<0)
	printf("Memory full\n");
	printf("Enter process no. page number and offset :");
	scanf ("%d",&pn);scanf ("%d",&pg);scanf ("%d",&of);
	printf("Physical address: %d\n",( (p[pn-1][pg-1]) * size + of));
}

