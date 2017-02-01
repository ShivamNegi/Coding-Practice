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

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		ll c, d, l;
		cin>>c>>d>>l;

		if(l % 4 != 0)
		{
			cout<<"no\n";
			continue;
		}
		else
		{
			ll val = l / 4;
			if(val <= c + d)
			{	
				ll min_val;
				ll carry = d * 2;
				if(carry > c)
					min_val = d;
				else
					min_val = d + c - carry;
				if(val >= min_val)
					cout<<"yes\n";
				else
					cout<<"no\n";
			}
			else
				cout<<"no\n";
		}
	}
    return 0;
}

