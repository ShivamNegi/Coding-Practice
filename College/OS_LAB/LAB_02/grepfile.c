#include <stdio.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, int *argv[])
{
 if(argc != 3)
	{
		printf("3 arguments required.");
		exit(0);
	}
 File  * fin;
 fin = open(argv[1], 'r');
 int len = strlen(argv[2]);
 char find[len];
 strcpy(find, argv);
 char line[100];
 for(getline(line, fin))
	{
	 	if(search(line, find)
			printf("%s", line);
	}
 return 0;
}
