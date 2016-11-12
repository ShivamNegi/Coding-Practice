#include <stdio.h>
#include <dirent.h>

int main()
{
  char dirname[10];
  DIR * p;
  struct dirent * dir;

  printf("Enter the directory path: ");
  scanf("%s", dirname);

  p = opendir(dirname);
  if(p)
    while(dir = readdir(p))
      printf("%s\n", dir->d_name);
  else
    printf("Error in opening directory %s.", dirname);
  return 0;
}
