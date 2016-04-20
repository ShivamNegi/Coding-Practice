#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 int t;
 //cin>>t;

 //while(t--)
 //{
  int n;
  //cin>>n;
  char a[] = {"abcdefghijklmnopqrstuvwxyz"};
  puts(a);
  char c1, c2;
  cin>>c1;
  cin>>c2;

  int pos1, pos2;
  pos1 = pos2 = 0;

  for(int i = 0; i < 26; i++)
    {
     if(a[i] == c1)
        {
         pos1 = i;

        }
     if(a[i] == c2)
        {
         pos2 = i;
        }
    }

    cout<<pos1<<endl<<pos2;


    int c = 1;
    for(;next_permutation(a + pos1, a + pos2);)
        c++;
    cout<<c;

 //}

 return 0;
}

