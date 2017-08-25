#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

/*
    Code Here!
*/

int main()
{
  int t;
  cin>>t;

  while(t--)
    {
      int x[2], y[2];
      int x1[2], y1[2];

      cin>>x[0]>>y[0]>>x[1]>>y[1];
      cin>>x1[0]>>y1[0]>>x1[1]>>y1[1];

      bool flag = true;

      if(x[0] == x[1] && x1[0] == x1[1] && x[0] == x1[0])
	{
	  int len = abs(y[0] - y[1]) + abs(y1[0] - y1[1]);
	  int a = min(y[0], y[1]);
	  int b = min(y1[0], y1[1]);
	  int c = min(a, b);

	  a = max(y[0], y[1]);
	    b = max(y1[0], y1[1]);
		  int d = max(a, b);
		  if(len <= d - c)
		    flag = false;
	}
      else if(y[0] == y[1] && y1[0] == y1[1] && y[0] == y1[0])
	{
	  int len = abs(x[0] - x[1]) + abs(x1[0] - x1[1]);
	  int a = min(x[0], x[1]);
	  int b = min(x1[0], x1[1]);
	  int c = min(a, b);

	  a = max(x[0], x[1]);
	    b = max(x1[0], x1[1]);
		  int d = max(a, b);
		  if(len <= d - c)
		    flag = false;	  
	}
      else
	{
	  flag = false;
	  for(int i = 0; i < 2; i++)
	    for(int j = 0; j < 2; j++)
	      if(x[i] == x1[j] && y[i] == y1[j])
		flag = true;
	}

      if(flag)
	cout<<"yes\n";
      else
	cout<<"no\n";      
    }
  return 0;
}

