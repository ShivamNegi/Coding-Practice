#include <iostream>

using namespace std;

int main()
{
	float val1, n1;
	cin>>val1>>n1;

	float val2, n2;
	cin>>val2>>n2;

	float res1, res2;
	res1 = val1 / n1;
	res2 = val2 / n2;

	if(res1 > res2)
		cout<<"first\n";
	else if(res1 < res2)
		cout<<"second\n";
	else
		cout<<"both\n";
	return 0;
}