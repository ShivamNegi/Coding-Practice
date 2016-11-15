#include <stdio.h>
#include <stdlib.h>

int n ;
typedef struct Data
{
	struct Data *l;
	struct Data *r; 
	char c;
	int f;
	int flag;
	int y;

}data;

typedef struct NODE
{
	struct NODE *l,*r;
	int wt;
	int flag;
	char a;

}node;

void disp(int x, data *n)
{
	if(n==NULL){return;}
	disp(x*10,n->l);
	disp(x*10+1,n->r);
	if(n->c!='$')
	{
		printf("%c\t%d\n",n->c,x);
	}
}

void Huff(data *d[])
{
	printf("!!!!!!!!!0\n");
	int i = 0, j = 0;
	for(i = 0; i<n; i++)
	{		
		for(j = 0 ; j < n-i-1;j++)
		{
			if(d[j]->f>d[j+1]->f)
			{
				data *t = d[j];
				d[j]=d[j+1];
				d[j+1] = t;				
			}		
		}	
	}
	int sp= 0 ;
	data* h = (data*)(malloc(sizeof(data)));
	int ii = 0;
	while(1)
	{
		
		if(d[(sp+1)%n]->flag!=1){
		int t = d[sp]->f+d[(sp+1)%n]->f;
		printf("merging\t%d\t%d\n",d[sp]->f,d[(sp+1)%n]->f);
		data *temp = (data*)(malloc(sizeof(data)));; 
		temp->l =d[sp];
		temp->r = d[sp+1];
		d[sp+1] = temp;
		temp->flag = 0;
		temp->f = t;
		d[sp]->flag = 1;
		temp->c = '$';
		printf("!!!!!!!!!1\n");
		for(j = sp+1 ; ; )
		{
			if(d[j]->f>d[j+1]->f)
			{
				data *temp2 = d[j];
				d[j] = d[j+1];
				d[j+1] = temp2;
				
				
				printf("!!!!!!!!!2\n");
			}
			j = (j+1)%n;
			if(d[j]->flag==1)
			{
				break;
			}
			printf("!!!!!!!!!3\n");
		}
		printf("!!!!!!!!!4\n");
		if(d[(sp+1)%n]->flag==1){break;}
		sp = (sp+1)%n;
		}
		else
		{
			break;
		}
		ii++;
		printf("!!!!!!!!!5\n");
	}
	
	printf("%d\n!!!!!!!!!!",d[sp]->f);
	for(i = 0 ; i < n; i++)
	{
		printf("%d\n",d[i]->f);
	
	}
	printf("\n!!!!!!!!!!\n");
	disp(0,d[sp]);

}



int main()
{
	data dddd ;
	printf("%c\n\n\n",dddd.c);
	int i = 0;
	int j = 0;
	printf("enter num of chars\n");
	scanf("%d",&n);
	
	char c[n+1]; 
	int  f[n+1];
	data *d[n+1];
	printf("enter freq\n");
	for(i = 0; i < n; i++)
	{
		d[i] = (data*)(malloc(sizeof(data)));
		getchar();
		scanf("%c",&c[i]);
		scanf("%d",&f[i]);
		printf("!!!!!!!!!!!!!!!!!\n");
	
		d[i]->c  = c[i];
		d[i]->f = f[i];
		d[i]->flag = 0;
		
	}
	printf("%d\n",i);	
	Huff(d);
    return 0;
}
