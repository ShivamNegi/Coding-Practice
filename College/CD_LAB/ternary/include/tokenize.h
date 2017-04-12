#include <stdio.h>

void insert_onechar_token(FILE * fpw, char ch)
{
    putc('<', fpw);
    putc(ch, fpw);
    putc('>', fpw);
}

void insert_twochar_token(FILE * fpw, char ch, char ch1)
{
    putc('<', fpw);
    putc(ch, fpw);
    putc(ch1, fpw);
    putc('>', fpw);
}

void insert_string_token(FILE * fpw, char * ch)
{
    putc('<', fpw);
    fputs(ch, fpw);
    putc('>', fpw);
}

void insert_num_token(FILE * fpw, char * num)
{
    fputs("<num,", fpw);
    fputs(num, fpw);
    putc('>', fpw);
}

void insert_id_token(FILE * fpw, char * id)
{
    fputs("<id,", fpw);
    fputs(id, fpw);
    putc('>', fpw);
}
