#include<iostream>
#include<math.h>

using namespace std;

int main()
{
 int t;
 cin>>t;

 while(t--)
    {
     int no;
     cin>>no;

     int n = sqrt(no * 2);

     if((n*(n + 1) / 2) > no)
        {
         n--;
         cout<<n;
        }
     else
        cout<<n;
     cout<<endl;
    }
 return 0;
}
