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

 for(i = 0; i < n; i++)
	{
		int j = 0;
		for(j = 0; j < n; j++)
			{
				if(arrive[i] < arrive[j])
					{	
						int temp = arrive[i];
						arrive[i] = arrive[j];
						arrive[j] = temp;

						temp = process[i];
						process[i] = process[j];
						process[j] = temp;
						
						temp = burst[i];
						burst[i] = burst[j];
						burst[j] = temp;
					} 
			}		
	}

 int waiting_time[n], turnaround_time[n], arrival_times[n];
 int waiting_counter, turnaround_counter, arrival_counter;
 waiting_counter = turnaround_counter = arrival_counter = 0;
 int time = 0;
 for(i = 0; i < n; i++)
	{
		waiting_time[waiting_counter++] = time;
		if(i != n - 1)
			printf("P%d->", process[i]);
		else
			printf("P%d\n", process[i]);
		arrival_times[arrival_counter++] = arrive[i];
		time += burst[i];
		turnaround_time[turnaround_counter++] = time;
	}

 int j;
 printf("The waiting times are: ");
 for(j = 0; j < n; j++)
	{
		if(j == n - 1)
			printf("%d\n", waiting_time[j] - arrival_times[j]);	
		else
			printf("%d, ", waiting_time[j] - arrival_times[j]);
	}
/*
 printf("The turnaround times are: ");
 for(j = 0; j < n; j++)
	{
		if(j == n - 1)
			printf("%d\n", turnaround_time[j] - arrival_times[j]);	
		else
			printf("%d, ", turnaround_time[j] - arrival_times[j]);
	}
*/
 return 0;
}
