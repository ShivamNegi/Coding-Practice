#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char * a;
    char ch;

    a = (char *)malloc(sizeof(char) * 100);
    printf("Enter the char: ");
    scanf("%c", &ch);

    strcpy(a, "a");
    if(strcmp(a, &ch) == 0)
        printf("The string is: %s\n", a);

    return 0;
}