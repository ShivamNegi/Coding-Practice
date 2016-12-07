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

 struct sockaddr_in server_address;
 
 sockfd=socket(AF_INET,SOCK_DGRAM,0);

 server_address.sin_family=AF_INET;
 server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
 server_address.sin_port=htons(1234);

 connect(sockfd,(struct sockaddr*)&server_address,sizeof(server_address));
 int no;
 printf("Enter the number: ");
 scanf("%d", &no);
 sendto(sockfd,&no,sizeof(no),0,(struct sockaddr*)&server_address,sizeof(server_address));
 int clen = sizeof(server_address);
 n = recvfrom(sockfd,&no,sizeof(no),0,(struct sockaddr*)&server_address, &clen);

 close(sockfd);
 return 0;
}