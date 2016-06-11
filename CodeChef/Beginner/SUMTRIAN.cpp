#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        int a[n][n];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                a[i][j] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i; j++)
            {            
                scanf("%d", &a[i][j]);                
            }
        }

        int currpos = 0;
        long long int sum = a[0][0];
        for(int i = 1; i < n; i++)
        {
            if(a[i][currpos] > a[i][currpos + 1])
            {
                sum += a[i][currpos];
            }
            else
            {
                sum += a[i][currpos + 1];
                currpos++;
            }
        }

        printf("%lld\n", sum);
    }

    return 0;
}