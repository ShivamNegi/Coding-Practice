#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(vector<int> arr, int size)
{
	for(int i = 0; i < size; i++)
		{
			cout<<arr[i]<<"\t";
		}
	cout<<endl;
}

int calculate(vector<int> arr, int k, int prod, int index)
{
	vector<int> options;

	for(int i = index + 1; i < arr.size(); i++)
	{
		if(arr[i] - arr[0] > 0 && arr[i] - arr[1] <= k)
			options.push_back(calculate(arr, k, prod * arr[i], i));
	}

	int min = options[0];
	for(int i = 0; i < options.size(); i++)
	{
		if(min > options[i])
			min = options[i];
	}

	return min;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int k;
		cin>>k;

		vector <int> arr;

		for(int i = 0; i < k; i++)
		{
			int no;
			cin>>no;
			arr.push_back(no);
		}

		cout<<calculate(arr, k, arr[0], 0);
	}

	return 0;
}