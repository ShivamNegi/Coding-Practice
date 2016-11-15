#include <stdio.h>
#include <string.h>

void display(int shift_table[])
{
    int i = 0;
    for(i; i < 26; i++)
    {
        printf("\n%c %d", 97 + i, shift_table[i]);
    }
}

void create_table(int * shift_table, char * check, int size)
{
    int i = 0;
    for(i = 0; i < 26; i++)
        shift_table[i] = size;
    for(i = 0; i < size - 1; i++)
        shift_table[check[i] - 'a'] = size - i - 1;
}

int main()
{
    char inp[100], check[100];
    int n1, n2, i;
    
    printf("Enter the main string length: ");
    scanf("%d", &n1);
    
    printf("Enter the string: ");    
    scanf (" %[^\n]%*c", inp);
    
    printf("Enter the check string length: ");
    scanf(" %d", &n2);
    
    printf("Enter the string: ");    
    scanf (" %[^\n]%*c", check);
    
    int shift_table[26];
    create_table(shift_table, check, n2);
    // display(shift_table);
    
    for(i = n2 - 1; i < n1;)
    {
        int j = i;
        int flag = 1;
        for(j; j > i - n2; j--)
        {
            if(inp[j] != check[n2 - (i - j) - 1])
            {
                i += shift_table[inp[j] - 'a'];
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("Substring found.\n");
            break;
        }
    }

    if(i > n1)
        printf("Substring Missing.\n");
    
    return 0;
}
