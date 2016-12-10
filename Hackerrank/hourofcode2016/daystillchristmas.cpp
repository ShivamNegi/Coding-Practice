#include <iostream>

using namespace std;

int main()
{
	string months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
	int non_leap[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int leap[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


	string inp;	
	cin>>inp;

	int day, year;
	cin>>day>>year;

	//not leap
	if(year % 4)
	{
		int current_day, christmas_day = 365 - 6;
		current_day = 0;

		for(int i = 0; i < 12; i++)
		{
			if(months[i] == inp)
				break;
			else
			{
				current_day += non_leap[i];
			}
		}
		current_day += day;

		if(current_day < christmas_day)
			cout<<christmas_day - current_day<<endl;
		else
			cout<<christmas_day + 365 - current_day<<endl;

	}//is leap
	else
	{
		int current_day, christmas_day = 366 - 6;
		current_day = 0;

		for(int i = 0; i < 12; i++)
		{
			if(months[i] == inp)
				break;
			else
			{
				current_day += leap[i];
			}
		}
		current_day += day;

		if(current_day < christmas_day)
			cout<<christmas_day - current_day<<endl;
		else
			cout<<christmas_day + 366 - current_day<<endl;
	}
	return 0;
}