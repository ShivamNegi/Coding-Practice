#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int main()
{
 string name;

 cin>>name;

 char a[name.size()];

 for(int i = 0; i < name.size(); i++)
    a[i] = name[i];

 int c = 1;

 while(next_permutation(a, a + strlen(a)))
    c++;

 cout<<c;

 cout<<endl<<name.substr(3)<<endl;

 return 0;
}
