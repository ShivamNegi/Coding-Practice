#include  <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include  <fcntl.h>

int main()
{
 int fp1 , fp2 ;
 fp1 = open("file.txt",O_RDONLY);

 
 char buf[100] ;
 int x = read(fp1,buf,sizeof(buf));
 close(fp1);
 fp2 = creat("abcd5.txt",777);
 write(fp2,buf, x);
 close(fp2);
 return 0; 
}
 
