#include <bits/stdc++.h>

using namespace std;

int remove(int no, int div)
{
  while(no % div == 0)
    no /= div;
  return no;
}

bool two_primes(int no)
{
  int counter = 0;
  for(int i = 2; i <= sqrt(no); i++)
    {
      if(no % i == 0)
	counter++;
    }
  return counter <= 2;
}

int main()
{
  int len, q;
  cin>>len>>q;

  vector<int> arr;
  for(int i = 0; i < len; i++)
    {
      int no;
      cin>>no;
      arr.push_back(no);
    }

  while(q--)
    {
      int val;
      cin>>val;

      bool flag = false;
      for(int i = 0; i < len; i++)
	{
	  if(two_primes(remove(val, arr[i])))
	    {
	      flag = true;
	      break;
	    }
	}
      if(flag)
	cout<<"YES\n";
      else
	cout<<"NO\n";
    }

  return 0;
}
