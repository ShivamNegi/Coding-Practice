#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct mesgq
{
	long type;
	char * text;
}msg;

int main()
{
	int msg_id, len;
	key_t key = 8000;
	
	if ((msg_id = msgget(key, 0644)) == -1)
		{
			printf("Server not active\n"); 
			exit(1);
		}
			
	printf("Client ready :\n");
	
	while (msgrcv(msg_id, &msg, sizeof(msg.text), 0, 0) != -1)
	{
		printf("From Server: \"%s\"\n", msg.text);
		//fgets(msg.text, sizeof(msg.text),stdin);
		
		char * line = msg.text;
		size_t len = 0;
		getline(&(msg->text), &len, stdin);
		//len = strlen(msg.text);
		//printf("%d", len);
		
		//if (msg.text[len-1] == '\n')
		//	msg.text[len-1] = '\0';
		msgsnd(*(msg->text), &msg, len+1, 0);
	}
	
	printf("Server Disconnected\n");
	return 0;
}
