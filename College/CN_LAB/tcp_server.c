#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/socket.h>
#define PORT_NO 1234

int main()
{
	int sockfd;
	struct sockaddr_in server_address;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if(sockfd < 0)
		perror("Socket error");

	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(PORT_NO);

	int ret = bind(sockfd, (struct sockaddr *)&server_address, sizeof(server_address));

	listen(sockfd, 5);

	int newsockfd = accept(sockfd, (struct sockaddr *)client_address, sizeof(client_address));

	
	return 0;
}