#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

FILE * open_file(char filename[100], char * param)
{
    FILE *fp;
    int c;

    fp = fopen(filename, param);

    if(fp == NULL)
    {
        perror("Open");
        exit(0);
    }
    return fp;
}

char * read_word(FILE * fpr, char ch)
{
    char * buffer = (char *) malloc(sizeof(char) * 100);
    int counter = 0;

    while((ch == '_' || isalnum(ch)) && ch != EOF)
    {
        buffer[counter++] = ch;
        ch = getc(fpr);
    }
    buffer[counter++] = '\0';
    if(counter > 1)        
        fseek(fpr, -1, SEEK_CUR);

    return buffer;
}