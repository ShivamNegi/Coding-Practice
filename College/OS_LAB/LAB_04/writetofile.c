#include  <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include  <fcntl.h>

int main()
{
 int fp ;
 char *buf = {"appleabcd"};
 fp = creat("file.txt",777);
 write(fp,buf, sizeof(buf));
 close(fp);
 return 0; 
}
 
