#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;

	int tmin, tsec;
	tmin = tsec = 0;

	while(t--)
	{
		int min, sec;
		cin>>min>>sec;

		tmin += min;
		tsec += sec;
	}

	int thours;
	tmin += tsec / 60;
	tsec = tsec % 60;
	thours = tmin / 60;
	tmin = tmin % 60;

	cout<<thours<<" "<<tmin<<" "<<tsec<<endl;

	return 0;
}