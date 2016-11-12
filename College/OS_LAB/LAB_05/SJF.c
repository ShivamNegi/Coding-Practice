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

 int time = 0, j;
 int waiting_time[n], turnaround_time[n];
 int waiting_counter, turnaround_counter;
 waiting_counter = turnaround_counter = 0;

 for(j = 0; j < n; j++)
	{
	 int possibilities[n], counter = 0;
	 waiting_time[waiting_counter++] = time;
 	 for(i = 0; i < n; i++)
		{
			if(arrive[i] <= time)
				{
				 possibilities[counter++] = process[i];
				}
		}
	 int shortest_job_no = possibilities[0];
	 for(i = 1; i < counter; i++)
		{
			int job_no = possibilities[i];
			if(burst[job_no - 1] < burst[shortest_job_no - 1])
				shortest_job_no = job_no;
		}
	 if(j != n - 1)
		 printf("P%d->", shortest_job_no);
	 else
		 printf("P%d\n", shortest_job_no);
	 time += burst[shortest_job_no - 1];
	 turnaround_time[turnaround_counter++] = time;
	 // printf("time: %d\n", time);
	 burst[shortest_job_no - 1] = 99999;
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


 return 0;
}
