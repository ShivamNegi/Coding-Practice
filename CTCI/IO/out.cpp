#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	//char * str1 = "abcd";
	int a[] = {1, 2, 3, 4, 5}, *p;
	p = a;
	++*p;
	printf("%d", *p);
	p += 2;
	printf("%d", *p);
	if(-1 || -2)
		printf("this is true.");
	else
		printf("this is false.");
	return 0;
}
