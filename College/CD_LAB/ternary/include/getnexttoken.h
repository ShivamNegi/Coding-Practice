#include "openfile.h"
#include "constants.h"
#include "parsing_fun.h"

_token getnexttoken(FILE * fpr)
{
  _token token;
  char * buffer = (char *) malloc(sizeof(char) * 100);
  char ch = getc(fpr);

  while(ch == ' ' || ch == '\t' || ch == '\n')
    ch = getc(fpr);

  if(ch == '\'')
  {
    skip_quotes_string(fpr, ch, '\'');
    buffer[0] = ch;
    buffer[1] = '\0';
  }
  else if(ch == '\"')
  {
    skip_quotes_string(fpr, ch, '\"');
    buffer[0] = ch;
    buffer[1] = '\0';
  }
  else if(check_relational_ops(ch))
  {
    char ch1;
    ch1 = getc(fpr);

    if(op_check_buffer(ch, ch1))
    {
      buffer[0] = ch;
      buffer[1] = ch1;
      buffer[2] = '\0';
    }
    else
    {
      buffer[0] = ch;
      buffer[1] = '\0';
      fseek(fpr, -1, SEEK_CUR);
    }
  }
  else if(check_arithmetic_ops(ch) || check_special_chars(ch) || check_bitwise_chars(ch))
  {
    buffer[0] = ch;
    buffer[1] = '\0';
  }
  else if(isdigit(ch))
  {
    buffer = read_word(fpr, ch);
    strcpy(buffer, "num");
  }
  else if(is_alpha_underscore(ch))
  {
    buffer = read_word(fpr, ch);

    if(!is_keyword(buffer))
      strcpy(buffer, "id");
  }

  strcpy(token.lexemename, buffer);
  token.index = 1;
  return token;
}

// Driver function
/*
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
    puts(getnexttoken(fpr, ch));
    ch = getc(fpr);
  }

  fclose(fpr);
  return 0;
}
*/
