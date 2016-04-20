#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

bool isPrime(int no)
{
 for(int i = 2; i <= sqrt(no); i++)
    {
     if(no % i == 0)
        return false;
    }

 return true;
}


int main()
{
 int a, b, k;

 cin>>a>>b>>k;
 int primes[100];
 int counter = 0;
 int enter = 0;

 for(int i = 2; i < 100; i++)
    {
     if(isPrime(i))
        primes[counter++] = i;
    }

 for(int i = a; i <= b; i++)
    {
     int kprimes = 0;
     for(int j = 0; primes[j] < a; j++)
        {
         if(i % primes[j] == 0)
            kprimes++;
        }
     if(kprimes == k)
        {            enter ++;        }
    }
 cout<<enter<<endl;
 return 0;
}

