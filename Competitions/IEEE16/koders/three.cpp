#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int a[100];
 int no1,no2,  i = 0;

 cin>>no1>>no2;

 while(no1 != 0)
    {
     a[i++] = no1;
     a[i++] = no2;
     cin>>no1>>no2;
    }

 for(int j = 0; j < i; j+= 2)
    {
     int a1 = a[j];
     int b = a[j + 1];

     int min_no;

     if(a1 < b)
        {
         min_no = a1;
        }
     else
        min_no = b;

     int c = a1 + b;
     int d = a1 * b;

     while(c % min_no != 0)
        {
         c = c / min_no;
        }

     while(d % min_no != 0)
        {
         d = d / min_no;
        }

     cout<<c<<" "<<d<<endl;
    }

 return 0;
}
