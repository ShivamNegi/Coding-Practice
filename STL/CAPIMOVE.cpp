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
		int g;
		cin>>g;
		
		vector< pi > pop;
		vvi graph(g);
		for(int i = 0; i < g; i++)
		{
			int val;
			cin>>val;
			pop.push_back(make_pair(i, val));
		}

		sort(all(pop), greater<int>());
		for(int i = 0; i < g; i++)
		{
			int x, y;
			cin>>x>>y;
			x--;y--;
			graph[x].push_back(y);
		}

		for(int i = 0; i < g; i++)
		{
			bool flag = false;
			for(int i = 0; i < g; i++)
			{
				
			}
		}
	}
    return 0;
}