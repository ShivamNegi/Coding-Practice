/*
parser for the following grammar
Program -> main() {declaration assign_stat}
declaration -> data-type identifier-list; declaration | @
data-type -> int char
identifier-list -> id | id, identifier-list
assign_stat -> id = id; | id = num
*/

#include "include/getnexttoken.h"
#include <stdlib.h>
#define PARSING_COMPLETE printf("Parsing Complete\n");
#define PARSING(buffer, variable) printf("Parsing \t--%s--\t\t--%s--\n", buffer, variable);
#define ERROR(buffer, variable) printf("Error while parsing --%s-- in production --%s\n", buffer, variable); exit(0);

// IMPORTANT: whenever a token is parsed we read the next token

_token token;
void Program(FILE * fpr);
void declarations(FILE * fpr);
void data_type(FILE * fpr);
void identifier_list(FILE * fpr);
void statement_list(FILE * fpr);
void statement(FILE * fpr);
void decision_stat(FILE * fpr);
void dprime(FILE * fpr);
void looping_stat(FILE * fpr);
void assign_stat(FILE * fpr);
void expn(FILE * fpr);
void eprime(FILE * fpr);
void simple_exp(FILE * fpr);
void seprime(FILE * fpr);
void term(FILE * fpr);
void tprime(FILE * fpr);
void factor(FILE * fpr);
void relop(FILE * fpr);
void addop(FILE * fpr);
void mulop(FILE * fpr);

void Program(FILE * fpr)
{
  PARSING(token.lexemename, "Program");
  if(ispresent_first_follow(token.lexemename, first_program))
  {
    token = getnexttoken(fpr);
    PARSING(token.lexemename, "Program");
    if(token.lexemename[0] == '(')
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "Program");
      if(token.lexemename[0] == ')')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "Program");
        if(token.lexemename[0] == '{')
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "Program");
          declarations(fpr);
          statement_list(fpr);

          if(token.lexemename[0] == '}')
          {
            PARSING_COMPLETE;
            return;
          }
        }
      }
    }
  }
  ERROR(token.lexemename, "Program");  
}

void declarations(FILE * fpr)
{
  PARSING(token.lexemename, "declarations");
  if(ispresent_first_follow(token.lexemename, first_declarations))
  {
    data_type(fpr);
    identifier_list(fpr);
    PARSING(token.lexemename, "declarations");
    if(token.lexemename[0] == ';')
    {
      token = getnexttoken(fpr);      
      declarations(fpr);
    }
  }
  else
  {
    if(ispresent_first_follow(token.lexemename, follow_declarations))
    {
      return;
    }
    else
    {
      ERROR(token.lexemename, "declaration");       
    }
  } 
}

void data_type(FILE * fpr)
{
  PARSING(token.lexemename, "data_type");
  if(ispresent_first_follow(token.lexemename, first_data_type))
  {
    token = getnexttoken(fpr);
    PARSING(token.lexemename, "data_type");
    return;
  }
  ERROR(token.lexemename, "data_type");  
}

void identifier_list(FILE * fpr)
{
  PARSING(token.lexemename, "identifier_list");
  if(ispresent_first_follow(token.lexemename, first_identifier_list))
  {
    token = getnexttoken(fpr);
    PARSING(token.lexemename, "identifier_list");
    if(token.lexemename[0] == ',')
    {
      token = getnexttoken(fpr);
      identifier_list(fpr);
      return;
    }
    else if(token.lexemename[0] == '[')
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "identifier_list");
      if(strcmp(token.lexemename, "num") == 0)
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "identifier_list");
        if(token.lexemename[0] == ']')
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "identifier_list");
          if(token.lexemename[0] == ',')
          {
            token = getnexttoken(fpr);
            identifier_list(fpr);
            return;
          }
          else
          {
            return;
          }
        }
      }
    }
    else
      return;
  }
  ERROR(token.lexemename, "identifier_list");
}

void statement_list(FILE * fpr)
{
  PARSING(token.lexemename, "statement_list"); 
  if(ispresent_first_follow(token.lexemename, first_statement_list))
  {
    statement(fpr);
    statement_list(fpr);    
    return;
  }
  else
  {
    if(ispresent_first_follow(token.lexemename, follow_statement_list))
      return;
  }    
  ERROR(token.lexemename, "statement_list");      
}

void statement(FILE * fpr)
{
  PARSING(token.lexemename, "statement");
  if(ispresent_first_follow(token.lexemename, first_statement))  
  {
    if(ispresent_first_follow(token.lexemename, first_assign_stat))
    {
      assign_stat(fpr);
      if(token.lexemename[0] == ';')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "statement");
        return;
      }
    }
    else if(ispresent_first_follow(token.lexemename, first_decision_stat))
    {
      decision_stat(fpr);
      return;
    }      
    else
    {
      looping_stat(fpr);
      return;
    }
  }  
  ERROR(token.lexemename, "statement");
}

void decision_stat(FILE * fpr)
{
  PARSING(token.lexemename, "decision_stat");
  if(ispresent_first_follow(token.lexemename, first_decision_stat))
  {
    token = getnexttoken(fpr);
    PARSING(token.lexemename, "decision_stat");
    if(token.lexemename[0] == '(')
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "decision_stat");
      expn(fpr);
      if(token.lexemename[0] == ')')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "decision_stat");
        if(token.lexemename[0] == '{') 
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "decision_stat");
          statement_list(fpr);
          if(token.lexemename[0] == '}')  
          {
            token = getnexttoken(fpr);
            PARSING(token.lexemename, "decision_stat");
            dprime(fpr);
            return;
          }
        }
      }
    }
  }
  ERROR(token.lexemename, "decision_stat");
}

void dprime(FILE * fpr)
{
  PARSING(token.lexemename, "dprime");
  if(ispresent_first_follow(token.lexemename, first_dprime))
  {
    token = getnexttoken(fpr);
    PARSING(token.lexemename, "assign_stat");
    if(token.lexemename[0] == '{')
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "assign_stat");
      statement_list(fpr);
      if(token.lexemename[0] == '}')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "assign_stat");
        return;
      }
    }
    else if(strcmp(token.lexemename, "if") == 0)
    {
      decision_stat(fpr);
      return;
    }
  }
  else
  {
    if(ispresent_first_follow(token.lexemename, follow_dprime))
      return;
  }
  ERROR(token.lexemename, "dprime");
   
}

void looping_stat(FILE * fpr)
{
  PARSING(token.lexemename, "looping_stat");
  if(ispresent_first_follow(token.lexemename, first_looping_stat))
  {
    if(strcmp(token.lexemename, "while") == 0)
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "looping_stat");
      if(token.lexemename[0] == '(')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "looping_stat");
        expn(fpr);
        if(token.lexemename[0] == ')')
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "looping_stat");
          if(token.lexemename[0] == '{')
          {
            token = getnexttoken(fpr);
            PARSING(token.lexemename, "looping_stat");
            statement_list(fpr);
            if(token.lexemename[0] == '}')
            {       
              token = getnexttoken(fpr);
              PARSING(token.lexemename, "looping_stat");       
              return;
            }
          }          
        }
      }
    }
    else if(strcmp(token.lexemename, "for") == 0)
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "looping_stat");
      if(token.lexemename[0] == '(')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "looping_stat");
        assign_stat(fpr);
        if(token.lexemename[0] == ';')
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "looping_stat");
          expn(fpr);
          if(token.lexemename[0] == ';')
          {
            token = getnexttoken(fpr);
            PARSING(token.lexemename, "looping_stat");
            assign_stat(fpr);
            if(token.lexemename[0] == ')')
            {
              token = getnexttoken(fpr);
              PARSING(token.lexemename, "looping_stat");
              if(token.lexemename[0] == '{')
              { 
                token = getnexttoken(fpr);
                PARSING(token.lexemename, "looping_stat");
                statement_list(fpr);
                if(token.lexemename[0] == '}')
                {
                  token = getnexttoken(fpr);
                  PARSING(token.lexemename, "looping_stat");
                  return; 
                }
              }              
            }
          }
        }
      }
    }
    else
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "looping_stat");
      if(token.lexemename[0] == '{')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "looping_stat");
        statement_list(fpr);
        if(token.lexemename[0] == '}')
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "looping_stat");
          if(strcmp(token.lexemename, "while") == 0)
          {
            token = getnexttoken(fpr);
            PARSING(token.lexemename, "looping_stat");
            if(token.lexemename[0] == '(')
            {
              token = getnexttoken(fpr);
              PARSING(token.lexemename, "looping_stat");
              expn(fpr);
              if(token.lexemename[0] == ')')
              {
                token = getnexttoken(fpr);
                PARSING(token.lexemename, "looping_stat");
                if(token.lexemename[0] == ';')
                {
                  token = getnexttoken(fpr);
                  PARSING(token.lexemename, "looping_stat");
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
  ERROR(token.lexemename, "looping_stat");
}

void assign_stat(FILE * fpr)
{
  PARSING(token.lexemename, "assign_stat");
  if(ispresent_first_follow(token.lexemename, first_assign_stat))
  {
    token = getnexttoken(fpr);
    PARSING(token.lexemename, "assign_stat");
    if(token.lexemename[0] == '=')
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "assign_stat");
      expn(fpr);
      return;
    }
  }
  else if(token.lexemename[0] == '}')
      return;
  ERROR(token.lexemename, "assign_stat");   
}

void expn(FILE * fpr)
{
  PARSING(token.lexemename, "expn");
  if(ispresent_first_follow(token.lexemename, first_expn))
  {
    if(token.lexemename[0] == '(')
    {
      token = getnexttoken(fpr);
      PARSING(token.lexemename, "expn");
      simple_exp(fpr);
      relop(fpr);
      simple_exp(fpr);
      if(token.lexemename[0] == ')')
      {
        token = getnexttoken(fpr);
        PARSING(token.lexemename, "expn");
        if(token.lexemename[0] == '?')
        {
          token = getnexttoken(fpr);
          PARSING(token.lexemename, "expn");
          expn(fpr);
          if(token.lexemename[0] == ':')
          {
            token = getnexttoken(fpr);
            PARSING(token.lexemename, "expn");
            expn(fpr);
            return;
          }          
        }  
      }
    }
    else
    {
      simple_exp(fpr);
      eprime(fpr);
      return;
    }      
  }
  //else
  //{
    ERROR(token.lexemename, "expn");
        
  //}
}

void eprime(FILE * fpr)
{
  PARSING(token.lexemename, "eprime");
  if(ispresent_first_follow(token.lexemename, first_eprime))
  {
    relop(fpr);
    simple_exp(fpr);
  }
  else
  {
    if(ispresent_first_follow(token.lexemename, follow_eprime))
    {
      return;
    }
    else
    {
      ERROR(token.lexemename, "eprime");
                
    }
  }
}

void simple_exp(FILE * fpr)
{
  PARSING(token.lexemename, "simple_exp");
  if(ispresent_first_follow(token.lexemename, first_simple_exp))
  {
    term(fpr);
    seprime(fpr);
  }
  else
  {
    ERROR(token.lexemename, "simple_exp");
        
  }
}

void seprime(FILE * fpr)
{
  PARSING(token.lexemename, "seprime");
  if(ispresent_first_follow(token.lexemename, first_seprime))
  {
    addop(fpr);
    term(fpr);
    seprime(fpr);
  }
  else
  {
    if(ispresent_first_follow(token.lexemename, follow_seprime))
    {
      return;
    }
    else
    {
      ERROR(token.lexemename, "seprime");
                
    }  
  }
}

void term(FILE * fpr)
{
  PARSING(token.lexemename, "term");
  if(ispresent_first_follow(token.lexemename, first_term))
  {
    factor(fpr);
    tprime(fpr);
  }
  else
  {
    ERROR(token.lexemename, "term");
        
  }
}

void tprime(FILE * fpr)
{
  PARSING(token.lexemename, "tprime");
  if(ispresent_first_follow(token.lexemename, first_tprime))
  {
    mulop(fpr);
    factor(fpr);
    tprime(fpr);
  }
  else
  {
    if(ispresent_first_follow(token.lexemename, follow_tprime))
    {
      return;
    }
    else
    {
      ERROR(token.lexemename, "tprime");
                
    }      
  }
}

void factor(FILE * fpr)
{
  PARSING(token.lexemename, "factor");
  if(ispresent_first_follow(token.lexemename, first_factor))
  {
    token = getnexttoken(fpr);
    return;
  }
  else
  {
    ERROR(token.lexemename, "factor");
        
  }
}

void relop(FILE * fpr)
{
  PARSING(token.lexemename, "relop");
  if(ispresent_first_follow(token.lexemename, first_relop))
  {
    token = getnexttoken(fpr);
    return;
  }
  else
  {
    ERROR(token.lexemename, "relop");
        
  }
}

void addop(FILE * fpr)
{
  PARSING(token.lexemename, "addop");
  if(ispresent_first_follow(token.lexemename, first_addop))
  {
    token = getnexttoken(fpr);
    return;
  }
  else
  {
    ERROR(token.lexemename, "addop");
        
  }
}

void mulop(FILE * fpr)
{
  PARSING(token.lexemename, "mulop");
  if(ispresent_first_follow(token.lexemename, first_mulop))
  {
    token = getnexttoken(fpr);
    return;
  }
  else
  {
    ERROR(token.lexemename, "mulop");
        
  }
}

int main()
{
  char filename[100];
  FILE * fpr;

  printf("Enter file to be read: ");
  scanf("%s", filename);
  fpr = open_file(filename, "r");

  printf("\n\n\t\tToken\t\tProduction\n");
  token = getnexttoken(fpr);
  Program(fpr);

  fclose(fpr);
  return 0;
}
