#include<iostream>
#include <math.h>

using namespace std;

int main()
{
	float mealCost;
	cin>>mealCost;

	int tipPercent;
	cin>>tipPercent;

	int taxPercent;
	cin>>taxPercent;

	float totalcost;
	totalcost = mealCost + mealCost * float(tipPercent) / 100 + mealCost * float(taxPercent) / 100;
	cout<<"The total meal cost is "<<round(totalcost)<<" dollars."<<endl;

	return 0;
}