#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
#define MAXLINE 1024

int main(int argc,char* argv[])
{
 int sockfd, n;
 socklen_t len;
 char sendline[1024],recvline[1024];

 struct sockaddr_in server_address;

 printf("\n Enter the message : ");
 scanf("%s",sendline);
 
 sockfd=socket(AF_INET,SOCK_DGRAM,0);

 server_address.sin_family=AF_INET;
 server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
 server_address.sin_port=htons(5035);

 connect(sockfd,(struct sockaddr*)&server_address,sizeof(server_address));
 sendto(sockfd,sendline,MAXLINE,0,(struct sockaddr*)&server_address,sizeof(server_address));
 n = recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
 printf("\n Server's Echo : %s\n\n",recvline);

 return 0;
}