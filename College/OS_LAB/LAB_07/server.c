#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <error.h>

struct mesgq
{
	long type;
	char text[200];
}msg;

int main()
{
	int msg_id, len;
	key_t key = 8000;
	
	if((msg_id = msgget(key, 0644|IPC_CREAT)) == -1)
		{
			perror("msgget");
			exit(1);
		}
	
	printf("Enter text, ^D toquit:\n");
	msg.type = 1;
	while(fgets(msg.text, sizeof(msg.text), stdin) != NULL)
	{
		len = strlen(msg.text);
		if (msg.text[len-1] == '\n')
			msg.text[len-1] = '\0';
		msgsnd(msg_id, &msg, len+1, 0);
		msgrcv(msg_id, &msg, sizeof(msg.text), 0, 0);
		printf("From Client: \"%s\"\n", msg.text);
	}
	msgctl(msg_id, IPC_RMID, NULL);
	return 0;
}