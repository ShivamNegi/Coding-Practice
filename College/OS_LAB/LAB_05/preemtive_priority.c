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
					} 
			}		
	}

 int time = 0;
 while(1)
	{
	 // checking if all processes have finished or not
	 // if priority is 999 the process is dead
	 int flag = 0;	
	 for(i = 0; i < n; i++)
		{
			if(priority[i] != 999)
				flag = 1;
		}
	 if(flag == 0)
		break;

	 // we reach here only when there is a switch of a process
	 // or at the beginning of time
	 int possibilities[n], counter = 0;
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

	 for(j = time + 1; j < time + burst[most_prior_job_no - 1]; j++)
		{
			// int possible[n], counter1 = 0;
			int k = 0;
			int prior_job_no = most_prior_job_no;
			for(k = 0; k < n; k++)
				{
					if(arrive[k] <= j)
						{
						 // printf("priority:%d, ", priority[process[k] - 1]);
						 int job_no = process[k];
						 if(priority[job_no - 1] < priority[prior_job_no - 1])
							prior_job_no = job_no;
						}
				}
		 	
		 	//printf("counter:%d\n", counter1);
			
			printf("prior_job_no: %d, time: %d, most_prior_job_no: %d\n", prior_job_no, j, most_prior_job_no);
			if(prior_job_no != most_prior_job_no)
				{					
					if(j == time + burst[most_prior_job_no - 1] - 1)
						{		
							priority[most_prior_job_no] = 999;
							printf("P%d->", most_prior_job_no);
						 	printf("killed\n");
						}
					else
						burst[most_prior_job_no - 1] = j - time;
					printf("unfinished buisness\n");

					break;
				}						
		}	
	
	 if(j >= time + burst[most_prior_job_no - 1] - 1)
						{		
							priority[most_prior_job_no] = 999;
							printf("P%d->", most_prior_job_no);
						 	printf("killed\n");
						}
	 time = j;	 
	 printf("time: %d\n", time);
	 if(i == 2)
	 	break;
	}
 return 0;
}
