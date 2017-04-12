#include <stdio.h>
#include <string.h>
#define DSIZE 5
#define MOD_VAL 20
#define SIZE_R_OPS 4
#define SIZE_A_OPS 5
#define SIZE_S_CHARS 10
#define SIZE_B_OPS 2
#define SIZE_KEYWORDS 33
#define MAX_TERM 20
#define END "end"

char relational_ops[SIZE_R_OPS] = {">=<!"};
char arithmetic_ops[SIZE_A_OPS] = {"+-*/%"};
char bitwise_ops[SIZE_B_OPS] = {"&|"};
char special_chars[SIZE_S_CHARS] = {"(){};,[]?:"};
char dtypes[DSIZE][10] = {"int", "float", "double", "char", "void"};
int dtype_sizes[DSIZE] = {4, 4, 8, 1, 4};
char keywords[SIZE_KEYWORDS][20] =
    {"auto","break","case","char",
"const","continue","default","do",
"double","else","enum","extern",
"float","for","goto","if",
"int","long","register","return",
"short","signed","sizeof","static"
"struct","switch","typedef","union",
"unsigned","void","volatile","while", "main"};

char first_program[][MAX_TERM] = {"main", END};
char first_declarations[][MAX_TERM] = {"int", "char", END};
char first_data_type[][MAX_TERM] = {"int", "char", END};
char first_identifier_list[][MAX_TERM] = {"id", END};
char first_statement_list[][MAX_TERM] = {"id", "if", "while", "for", "do", END};
char first_statement[][MAX_TERM] = {"id", "if", "while", "for", "do", END};
char first_decision_stat[][MAX_TERM] = {"if", END};
char first_dprime[][MAX_TERM] = {"else", END};
char first_looping_stat[][MAX_TERM] = {"while", "for", "do", END};
char first_assign_stat[][MAX_TERM] = {"id", END};
char first_expn[][MAX_TERM] = {"id", "num", "(", END};
char first_eprime[][MAX_TERM] = {"==", "!=", "<=", ">=", "<", ">", END};
char first_simple_exp[][MAX_TERM] = {"id", "num", END};
char first_seprime[][MAX_TERM] = {"+", "-", END};
char first_term[][MAX_TERM] = {"id", "num", END};
char first_tprime[][MAX_TERM] = {"*", "/", "%", END};
char first_factor[][MAX_TERM] = {"id", "num", END};
char first_relop[][MAX_TERM] = {"==", "!=", "<=", ">=", "<", ">", END};
char first_addop[][MAX_TERM] = {"+", "-", END};
char first_mulop[][MAX_TERM] = {"*", "/", "%", END};

char follow_declarations[][MAX_TERM] = {"id", "if", "while", "for", "do", END};
char follow_statement_list[][MAX_TERM] = {"}", END};
char follow_eprime[][MAX_TERM] = {";", ")", ":", END};
char follow_seprime[][MAX_TERM] = {";", ")", "==", "!=", "<=", ">=", "<", ">", ":", END};
char follow_tprime[][MAX_TERM] = {"+", "-", ";", ")", "==", "!=", "<=", ">=", "<", ">", ":", END};
char follow_dprime[][MAX_TERM] = {"id", "}", "while", "for", "do", END};

struct _token
{
  char lexemename[100];
  int index;
};

typedef struct _token _token;

// This function checks the first and follow
int ispresent_first_follow(char * buffer, char check_array[][MAX_TERM])
{
  int i;
  for(i = 0; i < MAX_TERM; i++)
  {
    if(strcmp(check_array[i], END) == 0)
      break;
    if(strcmp(check_array[i], buffer) == 0)
      return 1;
  }
  return 0;
}

// This function checks if the word read is a keyword.
int is_keyword(char * buffer)
{
  int i;
  for(i = 0; i < SIZE_KEYWORDS; i++)
  {
    if(strcmp(buffer, keywords[i]) == 0)
      return 1;
  }
  return 0;
}

// This function checks if the word read is a identifier.
int is_identifier(char * buffer, int * index)
{
  int j;
  for(j = 0; j < DSIZE; j++)
  {
    if(strcmp(buffer, dtypes[j]) == 0)
    {
      *index = j;
      return j;
    }
  }
  return 0;
}
