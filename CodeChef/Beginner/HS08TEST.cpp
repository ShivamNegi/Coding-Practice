#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int x;
    float y;
    cin>>x>>y;

    if(x >= y)
        printf("%.2f\n", y);
    else
    {
        if(x % 5 == 0)
        {
            y = y - x - 0.5;
            printf("%.2f\n", y);
        }
        else
            printf("%.2f\n", y);
    }   
    return 0;
}