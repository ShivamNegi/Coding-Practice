#include <stdio.h>

/*
    switch cae always takes "integral" values
*/

int main()
    {

        double ch;

        printf("enter a value btw 1 to 2:");

        scanf("%lf", &ch);

        switch (ch)

        {

        case 1:

            printf("1");

            break;

        case 2:

            printf("2");

            break;

        }
        return 0;
    }