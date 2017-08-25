#include <bits/stdc++.h>

using namespace std;

void display(vector< pair<int, int> > a)
{
  for(int i = 0; i < a.size(); i++)
    {
      cout<<a[i].first<<"\t"<<a[i].second<<endl;
    }
}

int main()
{
  int t;
  cin>>t;

  while(t--)
    {
      int n, d;
      cin>>n>>d;
      
      vector< pair<int, pair<int, int> > > inp;
      for(int i = 0; i < n; i++)
	{
	  int di, ti, si;
	  cin>>di>>ti>>si;

	  di--;
	  inp.push_back(make_pair(di, make_pair(si, ti)));
	}

      sort(inp.begin(), inp.end());

      int tot_sadness = 0;
      int j = 0, live = 0;
      vector< pair<int, int> > out;
      for(int i = 0; i < d; i++)
	{
	  for(j; j < n; j++)
	    {
	      if(inp[j].first == i)
		out.push_back(inp[j].second);
	      else
	        break;	
	    }	 
	  sort(out.begin() + live, out.end());
	  reverse(out.begin() + live, out.end());

	  if(live == out.size())
	    continue;
	  (out[live].second)--;
	  if(out[live].second == 0)
	    live++;
	}

      while(live < out.size())
	{
	  tot_sadness += out[live].first * out[live].second;
          live++;
	}

      cout<<tot_sadness<<endl;
    }
  return 0;
}
