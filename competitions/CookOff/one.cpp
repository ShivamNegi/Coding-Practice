#include<bits/stdc++.h>

using namespace std;

int main()
{
 long int t;
 cin>>t;

 long int sum = 0;
 long int extra, less;
 extra = less = 0;

 for(long int i = 0; i < t; i++)
    {
     long int no;
     cin>>no;
     if(no > 2)
     	extra += no - 2;
     else
     	less += 2 - no;
    }

 if(extra > less)
 {
 	sum = extra - less;
 	sum = ceil(float(sum) / 2) + t;
 	cout<<sum;
 }
 else
 {
 	cout<<t;
 }

 cout<<endl;
 
 return 0;
}
