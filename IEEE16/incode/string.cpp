#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int t;
 cin>>t;

 while(t--)
    {
     string a = "abcdefghijklmnopqrstuvwxyz";
     char z[] = {"abcdefghijklmnopqrstuvwxyz"};

     char c1, c2;

     cin>>c1>>c2;

     int pos1, pos2;

     pos1 = a.find(c1);
     pos2 = a.find(c2);

     int c = 0;

     while(next_permutation(z + pos1, z + pos2))
        c++;

     cout<<c<<endl;
    }


 return 0;
}
