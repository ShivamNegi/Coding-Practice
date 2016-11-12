#include <stdio.h>

int main()
{
 int n;
 printf("Enter the number of processes: ");
 scanf("%d", &n);
 
 int system[n], user[n];
 int sys_counter, user_counter, i = 0;
 sys_counter = user_counter = 0;

 for(i = 0; i < n; i++)
	{
 	 int b_time;
	 printf("Enter the burst time: ");
	 scanf(" %d", &b_time);
	 int isuser;
	 printf("Enter if isuser: ");
	 scanf(" %d", &isuser);

	 if(isuser)
		user[user_counter++] = b_time;
	 else
		system[sys_counter++] = b_time;	
	}

 for(i = 0; i < sys_counter; i++)
	{
	 printf("P%d->", system[i]);
	}

 for(i = 0; i < user_counter; i++)
	{
	 printf("P%d->", user[i]);
	}

 
 return 0;
}
