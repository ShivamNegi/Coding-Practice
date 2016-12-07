#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <math.h>

#define PORT 1234

int main()
{
	int sockfd;
	struct sockaddr_in server_addr;

	sockfd = socket(AF_INET, SOCK_DGRAM, 0);

	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	while(1)
	{
		bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

		int pid = fork();

		if(pid == 0)
		{
			int no, clen = sizeof(server_addr);
			recvfrom(sockfd, &no, sizeof(no), 0, (struct sockaddr *)&server_addr, &clen);
			no = sqrt(no);
			sendto(sockfd, &no, sizeof(no), 0, (struct sockaddr *)&server_addr, clen);
			exit(1);
		}
		else
			close(sockfd);
	}

	return 0;
}