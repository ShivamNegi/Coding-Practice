#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

/*
    Code Here!
*/

bool equal_check(vi a)
{
	for(int i = 0; i < a.size() - 1; i++)
		if(a[i] != a[i + 1])
			return false;
	return true;
}

void incr(vi& a, int val, int i)
{
	for(int j = 0; j < a.size(); j++)
		if(j != i)
			a[j] += val;
}

void decr(vi& a, int val, int i)
{
	for(int j = 0; j < a.size(); j++)
		if(j != i)
			a[j] -= val;	
}

int numberOfSteps(vi a, int pos)
{
	if(equal_check(a))
		return 0;
	if(pos == a.size())
		return 0;
	else
	{
		for(int i = pos; i < a.size(); i++)
		{
			int one, two, five;
			incr(a, 1, i);
			one = numberOfSteps(a, i);
			decr(a, 1, i);

			incr(a, 2, i);
			two = numberOfSteps(a, i);
			decr(a, 2, i);

			incr(a, 5, i);
			five = numberOfSteps(a, i);
			decr(a, 5, i);
		}
	}
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		vi a;

		for(int i = 0; i < n; i++)
		{
			int no;
			cin>>no;
			a.push_back(no);
		}
	}
    return 0;
}

