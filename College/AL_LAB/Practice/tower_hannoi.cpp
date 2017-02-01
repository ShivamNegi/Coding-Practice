#include <iostream>

using namespace std;

void tower(int level, char from, char aux, char to)
{
  if(level == 1){
     cout<<"\t\tMove disc 1 from "<<from<<" to "<<to<<"\n";
     return;
  }
  // This is a inorder traversal of the recursion tree.
  else{
     tower(level - 1, from, to, aux);
     cout<<"\t\tMove disc "<<level<<" from "<<from<<" to "<<to<<"\n";
     tower(level - 1, aux, from, to);
  }
}

int main()
{
 int n;

 cout<<"\n\t\t*****Tower of Hanoi*****\n";
 cout<<"\t\tEnter number of discs : ";
 cin>>n;
 cout<<"\n\n";
 tower(n,'A','B','C');
 return 0;
}