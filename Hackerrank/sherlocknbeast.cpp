#include<bits/stdc++.h>

using namespace std;

int main()
{
 int t;
 cin>>t;
 
 while(t--)
 {
  int no;
  cin>>no;
  
  int i, j;
  i = 0;
  bool flag = false;
  for( i; i <= no / 3; i++)
  	{
  	for( j = 0; j <= no / 5; j++)
  		{
  		if(3 * i + 5 * j == no)
  			{
  			flag = true;
  			break;
  			}
  		}
  		
  	}
  
  string out = "";
  
  if(!flag)
  	{
  	cout<<"-1"<<endl;
  	continue;
  	}
  for(int k = 0; k < i * 3; k++)
  {
   out = out + '5';
  }
  for(int k = 0; k < j * 5; k++)
  	out = out + '3';
  	
  cout<<out<<endl;
 }
 
 return 0;
}