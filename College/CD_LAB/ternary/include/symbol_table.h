/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MOD_VAL 40*/
typedef struct node
{
  int id;
  char lexeme[50];
  int size;
  char type[20];
  char scope;
}node;

typedef struct hash
{
  node data;
  struct hash *next;
}hash;

hash * symb_table[MOD_VAL];

void init()
{
  int i = 0;
  for(i; i < 20; i++)    
    symb_table[i] = NULL;
}

int hash_func(char * buffer)
{
    int i, val, len;

    val = 0;
    len = strlen(buffer);
    //printf("\t\t%s length is %d\t", buffer, len);

    for(i = 0; i < len; i++)
        val += (int)buffer[i];
    
    return val % MOD_VAL;
}

hash * insert_hash(node val)
{
    hash * temp = (hash *) malloc(sizeof(hash));

    temp->data.id = val.id;
    strcpy(temp->data.lexeme, val.lexeme);
    strcpy(temp->data.type, val.type);
    temp->data.size = val.size;
    temp->data.scope = val.scope;
    temp->next = NULL;

    return temp;
}

hash * push(node val, int pos)
{
    hash * head = symb_table[pos];

    if(head != NULL)
    {
        //printf("second insert %s\n", val.lexeme);
        hash * trav = head;

        while(trav->next)
            trav = trav->next;

        hash * temp = insert_hash(val);
        trav->next = temp;
        return head;
    }

    //printf("first insert %s\n", val.lexeme);
    hash * temp = insert_hash(val);
    return temp;
}

void insert_node(node val)
{
    int pos = hash_func(val.lexeme);
    //printf("insert -%s-position is: %d\n", val.lexeme, pos);
    symb_table[pos] = push(val, pos);
    //printf("inserted lexeme --%s--\n", symb_table[pos]->data.lexeme);
}

int search_table(char * word)
{
    int pos = hash_func(word); 
    //printf("position --%s-- = %d\n", word, pos);
    hash * trav = symb_table[pos];
    
    while(trav)
    {
        //printf("\t\tI am searching -%s-\n", trav->data.lexeme);
        if(strcmp(trav->data.lexeme, word) == 0)
            return trav->data.id;
        trav = trav->next;
    }
    return 0;
}

void display()
{
    int i;

    //printf("id\t\tlexeme\t\tsize\t\ttype\t\tscope\n");
    for(i = 0; i < MOD_VAL; i++)
    {
        hash *trav = symb_table[i];
        while(trav)
        {
            printf(" %d\t\t%s\t\t%d\t\t%s\t\t%c\n", trav->data.id, trav->data.lexeme, trav->data.size, trav->data.type, trav->data.scope);
            trav = trav->next;
        }
    }
}
