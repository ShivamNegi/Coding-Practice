#include <bits/stdc++.h>

using namespace std;

class PipeCuts
{
  double probability(vector<int> weldLocations, int L)
  {
    int len = weldLocations.size();
    double odds = 0;
    sort(weldLocations.begin(), weldLocations.end());
    for(int i = 0; i < len; i++)
      {
	for(int j = i + 1; j < len; j++)
	  {
	    if(weldLocations[i] >= L && weldLocations[j] - weldLocations[i] >= L
	       && 100 - weldLocations[j] >= L)
	      odds++;
	  }
      }
    return odds / (len * (len - 1));
  }
};
