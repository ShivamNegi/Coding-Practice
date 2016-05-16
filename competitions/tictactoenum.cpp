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

bool ispresent(long int fibnos[], long int no, long int n)
{
 for(long int i = 0; i < n; i++)
    {
     if(fibnos[i] == no)
        return true;
    }
 return false;
}


int main()
{
 long int t;
 long int fibnos[5000];
 long int n = 2;

 fibnos[0] = 0;
 fibnos[1] = 1;

 cin>>t;

 while(t--)
    {
     long int no;
     cin>>no;

     while(fibnos[n - 1] < no)
        {
            fibnos[n] = fibnos[n - 1] + fibnos[n - 2];
            n++;
        }

     /*for(long int i = 0; i < n; i++)
        {
         cout<<fibnos[i]<<" ";
        }*/

     long int sum = 0;
     for(long int i = 2; i < no; i++)
        {
            if(!ispresent(fibnos, i, n))
                sum += i;
        }

     if(isprime(sum))
        cout<<"Tic";
     else if(sum % 2 == 0)
        cout<<"Tac";
     else
        cout<<"Toe";
     cout<<endl;
    }
}
