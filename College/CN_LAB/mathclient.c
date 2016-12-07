#include <sys/types.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXLINE 1024

typedef struct mathe
{
	int op1;
	int op2;
	char opn;
}maths;

typedef struct pi
{
	float result;
	pid_t pid;
}ans;

int main(int argc, char *argv[])
{
	int sockfd;
	int n;
	maths arr;
	printf("Enter the first operator, operation, second operator : ");
	scanf("%d %c %d", &arr.op1, &arr.opn, &arr.op2);
	socklen_t len;
	ans asnwer;
	struct sockaddr_in servaddr;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servaddr.sin_port = htons(3000);
	connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	len = sizeof(servaddr);
	sendto(sockfd, &arr, sizeof(arr), 0, (struct sockaddr*)&servaddr, len);
	n = recvfrom(sockfd, &asnwer, sizeof(asnwer), 0 , NULL, NULL);
	printf("\nResult : %lf\nPID : %d\n", asnwer.result, asnwer.pid);
	return 0;
}
