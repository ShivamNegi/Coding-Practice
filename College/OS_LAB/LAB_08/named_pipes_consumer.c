#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <linux/stat.h>

#define FIFO_FILE "yolo"
#define SIZE 10

int counter;
int buffer[SIZE];

void * consumer (void * param)
{
	int item;
	
	sem_wait(&full);
	pthread_mutex_lock(&mutex);
	item=read();
	printf("\nConsumer has CONSUMED item: %d\n",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&empty);
}

int main()
{
	File *fp;
	char readbuf[80];
	counter = 0;
	
	umask(0);
	mknod(FIFO_FILE, S_FIFO|0666, 0);
	
	while(1)
	{
		fp = fopen(FIFO_FILE, "r");
	}
	
	for(i=0;i<n2;i++)
		pthread_create(&tidC[i],NULL,consumer,NULL);
	for(i=0;i<n2;i++)
		pthread_join(tidC[i],NULL);
	return 0;
}

