#include <stdio.h>
#include <stdlib.h>

int zeros = 0;

int insert(int *a, int n)
{
    int flag = 0;
    int counter = 0;
    for(int i = 0; i < n; i++)
        {
            int no;
            scanf("%d", &no);
            if(no != 0 || !flag)
                a[counter++] = no;
            else
                {
                    zeros++;
                    flag = 1;
                }
        }
    return counter;
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int out = 0; out < t; out++)
    {
        int n;
        //vi a, b, c, d;
        int counter = 0, eq;
        zeros = 0;

        //cin>>n>>eq;
        scanf("%d %d", &n, &eq);

        int *a, *b, *c, *d;
        a = (int *)malloc(sizeof(int) *n);
        b = (int *)malloc(sizeof(int) *n);
        c = (int *)malloc(sizeof(int) *n);
        d = (int *)malloc(sizeof(int) *n);

        int a_size = insert(a, n);
        int b_size = insert(b, n);
        int c_size = insert(c, n);
        int d_size = insert(d, n);

        for(int i = 0; i < a_size; i++)
        {
            for(int j = 0; j < b_size; j++)
            {
                for(int k = 0; k < c_size; k++)
                {
                    for(int l = 0; l < d_size; l++)
                    {
                        int val = a[i] ^ b[j] ^ c[k] ^ d[l];
                        if(val == eq)
                            {
                                counter++;
                            }
                    }
                }
            }
        }



        printf("Case #%d: ", out+1);
        printf("%d\n",counter+zeros);
    }

    return 0;
}

