#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector <int> arr, int n)
{
	for(int i = 0; i < n; i++)
		{
			cout<<arr[i]<<"\t";
		}
	cout<<endl;
}

int main()
{
	int t;

	cin>>t;

	vector <int> arr;

	for(int i = 0; i < t; i++)
		{
			int no;
			cin>>no;
			arr.push_back(no);
		}

	sort(arr.begin(), arr.end());
	display(arr, t);

	return 0;
}