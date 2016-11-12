#include <stdlib.h>
#include <stdio.h>
int main()
{
   int n;
   FILE *fptr;
   fptr=fopen("somefile.txt","w");
   if(fptr==NULL){
      printf("Error!");   
      exit(1);             
   }
   printf("Enter whatever!: ");
   char ch[30];
   scanf("%s", &ch);
   while(!ch)
	{
	 fprintf(fptr, "%s", ch);
	 scanf("%s", ch);
	}
   fclose(fptr);
   return 0;
}
