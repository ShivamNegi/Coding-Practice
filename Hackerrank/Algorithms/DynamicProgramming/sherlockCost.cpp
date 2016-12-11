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

int compute(vi a)
{
	ll res = 0;
	for(int i = 1; i < a.size(); i++)
	{
		res += abs(a[i] - a[i - 1]);
	}
	return res;
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		vi a, b(n);

		for(int i = 0; i < n; i++)
		{
			int no;
			cin>>no;
			a.push_back(no);
		}

		sort(all(a));

		if(a.size() % 2)
		{
			bool flag = false;
			int counter = n - 1;
			for(int i = 1; i < n - 1; i++)
			{
				if(flag)
					b[i] = a[counter--];
				else					
					b[i] = 1;
				flag = !flag;
			}
			b[0] = a[counter--];
			b[n - 1] = a[counter--];
		}
		else
		{
			bool flag = false;
			int counter = n - 1;
			for(int i = 0; i < n; i++)
			{
				if(flag)
					b[i] = a[counter--];
				else					
					b[i] = 1;
				flag = !flag;
			}
		}

		cout<<compute(b)<<endl;
	}

    return 0;
}

