#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

bool isPrime(int no)
{
 for(int i = 2; i < sqrt(no); i++)
    {
     if(no % i == 0)
        return false;
    }

 return true;
}

int main()
{
 return 0;
}
