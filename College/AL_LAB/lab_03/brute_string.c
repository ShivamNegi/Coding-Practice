#include <stdio.h>
#include <string.h>

int main()
{
 char a[100], b[100];
 printf("Enter the main string: ");
 scanf("%s", a);
 printf("Enter the substring to be searched: ");
 scanf("%s", b);

 int i, j, lena = strlen(a), lenb = strlen(b);
 int flag = 0;
 for(i = 0; i < lena; i++)
	{
     int counter = 0, ci = i;
     while(a[ci] == b[counter] && counter < lenb)
		{
			ci++;
			counter++;
		}

	 // this is a very important check
	 if(counter == lenb)
		{
			flag = 1;
			break;
		}
	} 
 if(flag == 1)
	printf("Substring found\n");
 else
	printf("Substring missing\n");
}
