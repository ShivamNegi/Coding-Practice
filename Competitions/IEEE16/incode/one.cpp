#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int divisors(long long int no)
{
 long long int sum = 0;
 for(int i = 1; i <= no / 2; i++)
    {
     if(no % i == 0)
        sum += i;
    }

    return sum;
}

int main()
{
 long long int t;
 cin>>t;

 if(divisors(t) == t)
    cout<<"yes";
 else
    cout<<"no";

 return 0;
}
