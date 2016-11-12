#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
 int id;
 id = fork();
 printf("id value : %d\n", id);
 if(id == 0)
	{
 	 printf("Child : Hello I am the child process\n");
	 printf("Child child's pid: %d\n", getpid());
	 printf("Child: parent's pid %d\n", getppid());
	}
 if(id > 0)
	{
 	 printf("Parent: hello i am the parent\n");
	 printf("Parent: My pid is %d\n", getpid());
	 printf("Parent: childs pid is %d\n", id);
	}
 return 0;
}
