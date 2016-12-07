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

int max_seq(vi a, int pos)
{
	int gcd_val;
 if(pos == a.size() - 1)
 	return 1;

 gcd_val = __gcd(a[pos], a[pos + 1]);
 if(gcd_val == 1)
 	return max_seq(a, pos + 1);
 else
 	return max(1 + max_seq(a, pos + 1), max_seq(a, pos + 1));
}

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int size;
		cin>>size;

		vi a;

		for(int i = 0; i < size; i++)
		{
			int no;
			cin>>no;
			a.push_back(no);
		}

		cout<<max_seq(a, 0)<<endl;
	}
    return 0;
}

