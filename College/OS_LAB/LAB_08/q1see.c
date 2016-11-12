#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 10

pthread_mutex_t mutex;
pthread_t tidP[20],tidC[20];
sem_t full, empty;
int counter;
int buffer[SIZE];

void initialize()
{
	pthread_mutex_init(&mutex,NULL);
	sem_init(&full,1,0);
	sem_init(&empty,1,SIZE);
	counter=0;
}

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

int read()
{
	return(buffer[--counter]);
}

void * producer (void * param)
{
	int item;
	
	item = write();
	sem_wait(&empty);
	pthread_mutex_lock(&mutex);
	printf("\nProducer has PRODUCED item: %d\n",item);
	pthread_mutex_unlock(&mutex);
	sem_post(&full);
}

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
	int n1,n2,i;
	initialize();
	
	printf("\nEnter the no of producers: ");
	scanf("%d",&n1);
	printf("\nEnter the no of consumers: ");
	scanf("%d",&n2);
	
	for(i=0;i<n1;i++)
		pthread_create(&tidP[i],NULL,producer,NULL);
	for(i=0;i<n2;i++)
		pthread_create(&tidC[i],NULL,consumer,NULL);
	for(i=0;i<n1;i++)
		pthread_join(tidP[i],NULL);
	for(i=0;i<n2;i++)
		pthread_join(tidC[i],NULL);
		
	return 0;
}
