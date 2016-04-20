#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int a[100];
 int no;

 char inp[] = {'rock', 'paper', 'scissor'};

 char b[10];
 char k[10];
 char p[10];

 gets(b);
 gets(k);
 gets(p);

 int b1;
 int k1, p1;

 for(int i = 0; i < 3; i++)
    {
     if(i == 0)
        {
         if(strcmp(b, 'rock'))
            {
             b1 = 1;
            }
         else if(strcmp(b, 'paper'))
            b1 = 2;
         else
            b1 = 3;
        }
     else if(i == 1 )
        {
         if(strcmp(k, 'rock'))
            {
             k1 = 1;
            }
         else if(strcmp(k, 'paper'))
            k1 = 2;
         else
            k1 = 3;
        }
     else
        {
         if(strcmp(p, 'rock'))
            {
             p1 = 1;
            }
         else if(strcmp(p, 'paper'))
            p1 = 2;
         else
            p1 = 3;
        }
    }


 if()
 return 0;
}

