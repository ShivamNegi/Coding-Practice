#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

long int fl,x,count;

void trun(long int m)
{
   long int s=0;
   long int a[7],b[7];
   long int i=0,j=1,k,p,d,n,cc=0,temp,c1,c2;
   n=m;
   while(m>0)
   {
       b[i]=m%10;
       m=m/10;
       i++;
   }
   j=0;
   while(j<i)  //BUG j<=i
   {
       a[j]=b[i-j-1]; //BUG: a[j]=b[i-j];
       j++;
   }
   d=count-1;
   s=0;
   cc=0;
   cout<<"\nThe Left Truncated Numbers are: \n";
   while(cc<count)
   {
       c1=d;
       c2=cc;
       s=0;
       while(c2<count)
       {
          p=pow(10,c1);
          temp=a[c2]*p;
          s=s+temp;     //BUG: s=temp;
          c1--;
          c2++;
       }
       cout<<"\n"<<setw(i)<<s;
       d--;
       cc++;
   }
   d=count-1;  
   s=0;
   cc=count-1; //BUG: cc=count;
   cout<<"\n\nThe Right Truncated Numbers are: \n";
   while(cc>=0)
   {
       c1=d;
       c2=0;
       s=0;
       p=1;
       while(c1>0)
       {
          p=p*10;
          c1--;
       }
       while(c2<=cc)
       {
          temp=a[c2]*p;
          p=p/10;
          s=s+temp;   //BUG: s=temp;
          c1--;
          c2++;
       }
       cout<<"\n"<<s;
       d--;
       cc--;
   }
}

int main()
{
    long int k,m,cnt;
    cout<<"\nEnter the Integer to truncatable from left and right: ";
    cin>>cnt;
    k=cnt;
    m=0;
    while(k>0)
    {
        m++;
        k=k/10;
    }
    count=m;
    trun(cnt);
    cout<<"\n\n";
    return 0;
}
