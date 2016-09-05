#include <stdio.h>
#include <string.h>


int set1[100], set2[100], prev_diff = 10000;
int minstore1[100], minstore2[100], minstorelen1, minstorelen2;

void clear(int * a, int len)
{
 int i = 0;
 for(i; i < len; i++)
	{a[i] = 0;}
}

void copy(int len1, int len2)
{
 int i;
 for(i = 0; i < len1; i++)
		minstore1[i] = set1[i];

 for(i = 0; i < len2; i++)
		minstore2[i] = set2[i];

 minstorelen1 = len1;
 minstorelen2 = len2;
}


int diff(int len1, int len2)
{
 int sum1, sum2, i;
 sum1 = sum2 = 0;

 for(i = 0; i < len1; i++)
	{
		sum1 += set1[i];
	}

 for(i = 0; i < len2; i++)
	{
		sum2 += set2[i];
	}
 return abs(sum1 - sum2);
}

void nextpower(int * a, int len)
{
 int i = 0;
 if(a[0] == 0)
	a[0] = 1;
 else
	{
		a[0] = 0;
		i = 1;
		while(a[i] == 1 && i < len)
			a[i++] = 0;
		if(i != len)
			a[i] = 1;
	}
}

int compare(int final[], int power[], int len)
{
 int i = 0;
 for(i; i < len; i++)
	{
		if(power[i] != final[i])
			return 0;
	}
 return 1;
}

void display(int a[], int size)
{
 int i = 0;
 for(i; i < size; i++)
	{
		printf("%d ", a[i]);
	}
 printf("\n");
}

void powervalueset(int power[], int a[], int len, int final[])
{
 while(!compare(final, power, len))
	{
	 clear(set1, len);
	 clear(set2, len);
	 int i, setl1, setl2;
	 setl1 = setl2 = 0;

	 for(i = 0; i < len; i++)
		{
			if(power[i] == 1)
				set1[setl1++] = a[i];
		    else
				set2[setl2++] = a[i];
		}
	 int val = diff(setl1, setl2);
	 if(val < prev_diff)
		{
            printf("Next Set\n");
            display(set1, setl1);
            display(set2, setl2);
		}
	
	 nextpower(power, len);
	}
	
	int i, setl1, setl2;
	setl1 = setl2 = 0;

	 for(i= 0; i < len; i++)
		{
			if(power[i] == 1)
				{
				  set1[setl1++] = a[i];
				}
		    else
				set2[setl2++] = a[i];
		}
	 int val = diff(setl1, setl2);
	 if(val == 0)
		{
            printf("Next Set\n");
            display(set1, setl1);
            display(set2, setl2);
		}
	 nextpower(a, len);
}

void powerset(int power[], int a[], int len, int final[])
{
 int counter;
 while(!compare(final, power, len))
	{
	 int i = 0;
 	 int arr[100];counter = 0;
	 clear(arr, len);
	 for(i; i < len; i++)
		{
			if(power[i] == 1)
				{
				  arr[counter++] = a[i];
				}
		}

	 if(counter!= 0)
		{
			//display(arr, counter);
			 int from[counter + 1], to[counter + 1];
	 for(i=0; i < counter; i++)
		{
			from[i] = 0;
			to[i] = 1;
		}
	    powervalueset(from, arr, counter, to);
	 
		}
		nextpower(power, len);
	}
	
	int from[len + 1], to[len + 1], i;
	 for(i=0; i < len; i++)
		{
			from[i] = 0;
			to[i] = 1;
		}
	 powervalueset(from, a, len, to);	 
}

int main()
{
 int len;
 scanf(" %d", &len);

 int a[len], i;
 int power[len + 1], final[len + 1];

 for(i = 0; i < len; i++)
	{
		scanf(" %d", &a[i]);
 		power[i] = 0;
		final[i] = 1;
	}

  powerset(power, a, len, final);
  return 0;
}
