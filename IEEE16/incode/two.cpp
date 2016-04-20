#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int t;
 char a[100];
 int c = 0;
 cin>>t;

 while(t--)
    {
     int n;
     cin>>n;
     int no = n;
     int nh = 0, nf = 0, nt = 0, n5 = 0, n1 = 0;

     for(; no / 100 != 0; )
        {
         nh ++;
         no = no - 100;
        }

     for(;no / 50 != 0;)
        {
         nf ++;
         no = no - 50;
        }

    if(nf > 3)
        {
         no = n - no;
        }

    for(; no / 10 != 0; )
        {
         nt ++;
         no = no - 10;
        }

    if(nf > 3)
        {
         no = n - no;
        }

     for(; no / 5 != 0; )
        {
         n5 ++;
         no = no - 5;
        }

     if(nf > 3)
        {
         no = n - no;
        }

     n1 = no;
     cout<<nh<<endl<<nf<<endl<<nt<<endl<<n5<<endl<<n1;

    /*

     for(int i = 0; i < nh; i++)
        {
        }
     for(int i = 0; i < nf; i++)
     for(int i = 0; i < nt; i++)
     for(int i = 0; i < n5; i++)
     for(int i = 0; i < n1; i++)
    */

    }



 return 0;
}
