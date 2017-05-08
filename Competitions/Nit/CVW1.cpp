// newPr.cpp : Defines the entry poshort for the console application.
//


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <bitset>
#include <algorithm>


using namespace std;

short k, n;

void display(vector<short> a)
{
	for (short i = 1; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool fx(short x, vector<short> a)
{
	bool flag1, flag2;
	flag1 = false;
	flag2 = false;

	if (x == n + 1)
	{
		display(a);
		return true;
	}

	if (x > k && a[x - k] == -1)
	{
		
		a[x - k] = x;
		//cout << x << "\n"; display(a);
		flag1 = fx(x + 1, a);
		a[x - k] = -1;
		if (flag1) { return true; }
		//flag1 = false;
	}
	
	if ((x+k<=n)&&(a[x + k] == -1))
	{
		a[x + k] = x;
		//cout << x << "\n"; display(a);
		flag2 = fx(x + 1, a);
		a[x + k] = -1;
		if (flag2) { return true; }
		//flag2 = false;
	}

	return (flag1 || flag2);
}

int main()
{

	//cout << "aaaaa\n";
	short t;
	cin >> t;

	while (t--)
	{
		short x;
		cin >> x >> k;

		n = x;
		vector<short> a(n+1);

		fill(a.begin(), a.end(), -1);
		bool res = fx(1, a);
		if (!res)cout << "CAPTAIN AMERICA EVADES\n";
	}
	return 0;
}