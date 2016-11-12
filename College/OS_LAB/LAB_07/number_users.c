#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int fd[2];
    pipe(fd);
        
    if(fork())
    { 
    	close(fd[1]);  
        dup2(fd[0], 0);
        execlp("wc", "wc", "-l",NULL);
    }
    else
    {
        dup2(fd[1], 1);
        execlp("who", "who", NULL);
    }
    return 0;
}
