#include "include/getnexttoken.h"

int main()
{
  char filename[100];
  FILE * fpr;

  printf("Enter file to be read: ");
  scanf("%s", filename);
  fpr = open_file(filename, "r");

  char ch = getc(fpr);

  while(ch != EOF)
  {
    fseek(fpr, -1, SEEK_CUR);
    printf("<%s>", getnexttoken(fpr));
    ch = getc(fpr);
  }

  fclose(fpr);
  return 0;
}
