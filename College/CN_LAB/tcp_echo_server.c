#include <stdio.h>
#include <stdlib.h>	// for exit system call
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT_NO 1234

void main()
{
	int sockfd, newsockfd;
	struct sockaddr_in server_address, client_address;
	char message[100];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
	{
		printf("Error in creating socket.\n");
		exit(1);
	}


	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(PORT_NO);

	int ret = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

	if(ret < 0)
	{
		printf("Error in Binding.\n");
		exit(1);
	}

	printf("listening\n");
	listen(sockfd, 5);

	newsockfd = accept(sockfd, (struct sockaddr *)&client_address, sizeof(client_address));

	printf("Accepted\n");

	read(newsockfd, message, 100);
	printf("The client message is %s\n", message);
	printf("\n");

	
	close(sockfd);
	return;
}