#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    long long int n, k;
    long long int counter = 0;
    scanf("%lld", &n);
    scanf("%lld", &k);

    while(n--)
    {
        long long int no;
        scanf("%lld", &no);

        if(no % k == 0)
            counter++;
    }

    printf("%lld\n", counter);
    return 0;
}