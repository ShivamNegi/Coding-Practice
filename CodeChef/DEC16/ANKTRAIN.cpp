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

	int a[] = {4, 5, 6, 1, 2, 3, 8, 7};
	string pos[] = {"LB", "MB", "UB", "LB", "MB", "UB", "SU", "SL"};

	while(t--)
	{
		int n;
		cin>>n;

		n--;
		cout<<a[n % 8] + n - n % 8<<pos[n % 8]<<endl;
	}
    return 0;
}

