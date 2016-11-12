#include<stdio.h>
#include<stdlib.h>
void main()
{
	int proc1[10],bur1[10],pri1[10],proc2[10],bur2[10],pri2[10],sys,temp,i,j,n,k=0,t=0;
	printf("enter the number of processes");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter category(1.system 2.user),process no, burst time(ms) and priority  of %d process\n",i);
		scanf("%d",&sys);
		if(sys==1)
		{
			scanf("%d",&proc1[k]);
			scanf("%d",&bur1[k]);
			scanf("%d",&pri1[k]);
			k++;
		}
		else
		{
			scanf("%d",&proc2[t]);
			scanf("%d",&bur2[t]);
			scanf("%d",&pri2[t]);
			t++;
		}
	}
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(pri1[i]>pri1[j])
			{
				temp=proc1[i];
				proc1[i]=proc1[j];
				proc1[j]=temp;
				temp=bur1[i];
				bur1[i]=bur1[j];
				bur1[j]=temp;
				temp=pri1[i];
				pri1[i]=pri1[j];
				pri1[j]=temp;
 			}
		}
	}
	for(i=0;i<t-1;i++)
	{
		for(j=i+1;j<t;j++)
		{
			if(pri2[i]>pri2[j])
			{
				temp=proc2[i];
				proc2[i]=proc2[j];
				proc2[j]=temp;
				temp=bur2[i];
				bur2[i]=bur2[j];
				bur2[j]=temp;
				temp=pri2[i];
				pri2[i]=pri2[j];
				pri2[j]=temp;
 			}
		}
	}

	int waiting_time[n], turnaround_time[n];
	int waiting_counter, turnaround_counter, time;
	waiting_counter = turnaround_counter = time = 0;

	printf("multi-level queue scheduling\n");
	printf("process \t burst time \t priority\t category\n");
	for(i=0;i<k;i++)
		{
			waiting_time[waiting_counter++] = time;
			printf("%d \t\t %d \t\t %d \t\t system process\n",proc1[i],bur1[i],pri1[i]);
			time += bur1[i];
			turnaround_time[turnaround_counter++] = time;
		}
		
	for(i=0;i<t;i++)
		{
			waiting_time[waiting_counter++] = time;
			printf("%d \t\t %d \t\t %d \t\t user process\n",proc2[i],bur2[i],pri2[i]);
			time += bur2[i];
			turnaround_time[turnaround_counter++] = time;
		}

 printf("The waiting times are: ");
 for(j = 0; j < n; j++)
	{
		if(j == n - 1)
			printf("%d\n", waiting_time[j]);	
		else
			printf("%d, ", waiting_time[j]);
	}
 printf("The turnaround times are: ");
 for(j = 0; j < n; j++)
	{
		if(j == n - 1)
			printf("%d\n", turnaround_time[j]);	
		else
			printf("%d, ", turnaround_time[j]);
	}
}






	
