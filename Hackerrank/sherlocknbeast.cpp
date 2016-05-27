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
  i = j = 0;
  bool flag = false;

  //the first loop keeps count of the 5's
  //we start counting the 5's as their number is according
  //to the descending order of the keys
  for( i = 0; i <= no / 3; i++)
  	{
  	for( j = 0; j <= no / 5; j++)
  		{
  		if(3 * i + 5 * j == no)
  			{
  			flag = true;
  			break;
  			}
  		}
      if(flag)	
        break;
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