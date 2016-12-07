#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <error.h>
#define PORT 1234

int main()
{
	int sockfd, clientfd;
	struct sockaddr_in server_addr, client_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
	{
		perror("Error in creating socket");
		exit(1);
	}

	if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("Error in binding.");
		exit(1);
	}

	printf("Listening:\n");
	listen(sockfd, 5);

	while(1)
	{
		clientfd = accept(sockfd, (struct sockaddr *)&client_addr, sizeof(client_addr));

		int pid = fork();

		if(pid ==)
		{
			close(sockfd);
		}
		else
			close(clientfd);
	}
	return 0;
}