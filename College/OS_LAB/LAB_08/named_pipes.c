#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/stat.h>

#define FIFO_FILE "yolo"

int counter;
int buffer[SIZE];

int ispresent(int item)
{
 int i = 0;
 for(i; i < counter; i++)
		{
			if(buffer[i] == item)
				return 1;
		}
 return 0;
}

int write()
{
	int item=rand()%5;
	while(ispresent(item))
	{
		item=rand()%5;
	}
	buffer[counter++]=item;
	return item;
}

void * producer (void * param)
{
	int item;
	
	item = write();
	printf("\nProducer has PRODUCED item: %d\n",item);
}

int main()
{
	File *fp;
	char readbuf[80];
	
	umask(0);
	mknod(FIFO_FILE, S_FIFO|0666, 0);
	
	while(1)
	{
		fp = fopen(FIFO_FILE, "r");
				
	}
	
	for(i=0;i<n1;i++)
		pthread_create(&tidP[i],NULL,producer,NULL);
	for(i=0;i<n1;i++)
		pthread_join(tidP[i],NULL);
	return 0;
}
