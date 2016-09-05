#include <stdio.h>

void display(int a[][10], int size)
{
    int i = 0, j = 0; 
    for(i; i < size; i++)
    {
        for(j; j < size; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int size;
    scanf("%d", &size);

    int a[size][size], i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
            scanf("%d", &a[i][j]);
    }

    int res[size][size], k;

    for(k = 0; k < size; k++)
    {
        int out = 0;
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                out += a[k][j] * a[j][k];
            }
            res[k][i] = out;
        }
    }

    display(res, size);
    return 0;
}