#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define allr(c) c.rbeing(), c.rend()
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

void display_vipi(vector< pi > a)
{
	for(int i = 0; i < a.size(); i++)
		cout<<a[i].first<<"\t";
	cout<<endl;
}

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

		sort(pop.rbegin(), pop.rend());
		//display_vipi(pop);
		for(int i = 0; i < g - 1; i++)
		{
			int x, y;
			cin>>x>>y;
			x--;y--;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for(int i = 0; i < g; i++)
		{
			int val = -1;
			for(int j = 0; j < g; j++)
			{
				bool ispresent = false;
				for(int k = 0; k < graph[i].size(); k++)
				{
					if(pop[j].first == graph[i][k] || pop[j].first == i)
					{
						ispresent = true;
						break;
					}
				}
				if(ispresent == false)
				{
					val = pop[j].first;
					break;
				}
			}
			cout<<val + 1<<" ";
		}
		cout<<endl;
	}
    return 0;
}