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

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int x, y;
	int posx1, posy1, posx2, posy2;

	if(y > x)
		swap(&x, &y);

	int val1;
	val1 = ceil(sqrt(x));

	if(val1 % 2)
	{
		int diff = val1 * val1 - x;

		if(diff >= val1)
		{
			posy1 = diff - val1 + 1;
			posx1 = val1 - diff - 1;
		}
		else
		{
			posy1 = 0;
			posx1 = val1 - diff - 1;
		}
	}
	else
	{
		int diff = val1 * val1 - x;

		if(diff >= val1)
		{
			posy1 = (val1 - 1) - (diff - val1 + 1);
			posx1 = 

		}
		else
		{
			posy1 = val1 - 1;
		}
	}

    return 0;
}

