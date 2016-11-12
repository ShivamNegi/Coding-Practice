#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 printf("I am a good samaritan, then why!?\n");
 execvp(argv[1], &argv[1]);
 printf("I am alive.\n");
 perror("exec failure");
 exit(1);
}
