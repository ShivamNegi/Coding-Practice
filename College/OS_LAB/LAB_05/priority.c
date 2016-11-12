#include <stdio.h>

int main()
{
 int n;
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 
 int arrive[n], burst[n], priority[n], process[n];

 printf("Enter the arrival times\n");
 int i = 0;
 for(i = 0; i < n; i++)
	{
 	 scanf("%d", &arrive[i]);
	 process[i] = i + 1;
	}
 printf("Enter the burst times\n");
 for(i = 0; i < n; i++)
	{
 	 scanf("%d", &burst[i]);
	}
 printf("Enter the priorities\n");
 for(i = 0; i < n; i++)
	{
 	 scanf("%d", &priority[i]);
	}

 int time = 0;
 int waiting_time[n], turnaround_time[n];
 int waiting_counter, turnaround_counter;
 waiting_counter = turnaround_counter = 0;
 for(i = 0; i < n; i++)
	{
	 int possibilities[n], counter = 0;
	 waiting_time[waiting_counter++] = time;
	 int j = 0;
 	 for(j = 0; j < n; j++)
		{
			if(arrive[j] <= time)
				{
				 possibilities[counter++] = process[j];
				}
		}
 	
	 int most_prior_job_no = possibilities[0];
	 for(j = 1; j < counter; j++)
		{
			int job_no = possibilities[j];
			if(priority[job_no - 1] < priority[most_prior_job_no - 1])
				most_prior_job_no = job_no;
		}
	if(i != n - 1)
		 printf("P%d->", most_prior_job_no);
	else
		 printf("P%d\n", most_prior_job_no);
	time += burst[most_prior_job_no - 1];
	turnaround_time[turnaround_counter++] = time;
	priority[most_prior_job_no - 1] = 99999;
	}


 printf("The waiting times are: ");
 int total = 0, j;
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


 return 0;
}
