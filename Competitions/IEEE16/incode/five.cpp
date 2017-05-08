#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int t;
 cin>>t;

 while(t--)
    {
     int n, diff;
     int a[20];

     cin>>n>>diff;

     for(int i = 0; i < n; i++)
        {cin>>a[i];}

     sort(a, a + n);

     for(int i = 0; i < n; i++)
        {cout<<a[i]<<"\t";}

    }
}
