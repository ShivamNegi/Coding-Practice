#include<iostream>
#include<math.h>

using namespace std;

bool isprime(long int no)
{
 for(long int i = 2; i <= sqrt(no); i++)
    {
     if(no % i == 0)
        return false;
    }
 return true;
}

int main()
{
 long int t;

 cin>>t;

 while(t--)
    {
     long int no;
     cin>>no;

     long int sum = 0;
     for(long int i = 1; i < no; i++)
        {
         sum += i;
        }

     long int a = 1, b = 1;

     while(b < no)
        {
         sum -= b;
         long int temp = b;
         b = a + b;
         a = temp;
        }

    if(isprime(sum))
        cout<<"Tic";
     else if(sum % 2 == 0)
        cout<<"Tac";
     else
        cout<<"Toe";
     cout<<endl;

    }
 return 0;
}
