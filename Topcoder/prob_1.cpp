#include <bits/stdc++.h>

using namespace std;

class QuizShow
{
public:
  int wager(vector<int> score, int val1, int val2)
  {
    int bet = 0, best_odds = 0;

    for(int wage = 0; wage <= score[0]; wage++)
      {
	int odds = 0;Pi
	for(int i =  -1; i < 2; i += 2)
	  for(int j = -1; j < 2; j += 2)
	    for(int k = -1; k < 2; k += 2)
	      {
		if(score[0] + i * wage > score[1] + j * val1 &&
		   score[0] + i * wage > score[2] + k * val2)
		  odds++;
	      }
	if(odds > best_odds)
	  {
	    best_odds = odds;
	    bet = wage;
	  }
      }
    return bet;
  }
};
