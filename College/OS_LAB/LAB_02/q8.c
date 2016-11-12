#include <stdio.h>
#include <fcntl.h>

int main(int argc, char * argv[])
{
 FILE *fp, *fp2;
 char *C;
 fp = fopen(argv[1], 'r');
 fp2 = fopen(argv[2], 'w');
 fread(&C, 1, 5, fp);
 fwrite(C, 1, 3, fp2);
 fclose(fp);
 fclose(fp2);
 return 0;
}
