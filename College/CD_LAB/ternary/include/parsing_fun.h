#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// This function checks if character is a relational operator.
int check_relational_ops(char ch)
{
 int i = 0;
 for(; i < SIZE_R_OPS; i++)
    if(ch == relational_ops[i])
        return 1;
 return 0;
}

// This function checks if character is a arithmetic operator.
int check_arithmetic_ops(char ch)
{
 int i = 0;
 for(; i < SIZE_A_OPS; i++)
    if(ch == arithmetic_ops[i])
        return 1;
 return 0;
}

// This function checks if character is a special character.
int check_special_chars(char ch)
{
 int i = 0;
 for(; i < SIZE_S_CHARS; i++)
    if(ch == special_chars[i])
        return 1;
 return 0;
}

// This function checks if character is a bitwise operator.
int check_bitwise_chars(char ch)
{
 int i = 0;
 for(; i < SIZE_B_OPS; i++)
    if(ch == bitwise_ops[i])
        return 1;
 return 0;
}

// This function checks using lookahead for ">=", ">", ">>", "<", "<=", "<<"
// "==", "=", "|"
int op_check_buffer(char ch1, char ch2)
{
 switch(ch1)
 {
  case '>':
            if(ch2 == '=' || ch2 == '>')
                return 1;
            else
                return 0;
            break;
  case '<':
            if(ch2 == '=' || ch2 == '<')
                return 1;
            else
                return 0;
            break;
  case '=':
            if(ch2 == '=')
                return 1;
            else
                return 0;
            break;
  case '!':
            return 1;
 }
}

// This function checks if the first character conforms to variable naming rules
int is_alpha_underscore(char ch)
{
 if(isalnum(ch) || ch == '_')
    return 1;
 return 0;
}

// This function converts `id` of a symbol table entry to string.
char * get_char_id(int id)
{
    char * rev_no, * num;
    int counter, i;

    rev_no = (char *) malloc(sizeof(char) * 10);
    num = (char *) malloc(sizeof(char) * 10);
    counter = i = 0;

    while(id > 0)
    {
        rev_no[counter++] = '0' + id % 10 ;
        id /= 10;
    }

    while(counter >= 0)
        num[i++] = rev_no[--counter];

    num[i++] = '\0';

    return num;
}

// This function checks if the variable is global or not.
int is_global(char * buffer)
{
    if(strcmp(buffer, "main") == 0)
        return 0;
    return 1;
}


// This function converts character array to integer.
int char_to_int(char * buffer)
{
    int no, len, i;

    no = 0;
    len = strlen(buffer);

    for(i = 0; i < len; i++)
    {
        no = no * 10 + (int)(buffer[i] - '0');
    }
    return no;
}

// This function is used to skip quotes in a string be it '' or "".
void skip_quotes_string(FILE * fpr, char ch, char quote)
{
    int flag = 0, next_pos, start_pos;

    start_pos = ftell(fpr);
    ch = getc(fpr);

    while(1)
    {
        if(ch == quote)
        {
            int even = 0;
            next_pos = ftell(fpr);
            fseek(fpr, -2, SEEK_CUR);

            while(1)
            {
                ch = getc(fpr);
                if(ch != '\\' || ftell(fpr) == start_pos)
                {
                    if(even % 2 && even > 0)
                    {
                        fseek(fpr, next_pos, SEEK_SET);
                        break;
                    }
                    else
                    {
                        flag = 1;
                        break;
                    }
                }
                fseek(fpr, -2, SEEK_CUR);
                even++;
            }
        }

        if(flag)
        {
            fseek(fpr, next_pos, SEEK_SET);
            break;
        }
        ch = getc(fpr);
    }
}
