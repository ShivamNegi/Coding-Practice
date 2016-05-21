#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		char colors[n];
		cin>>colors;

		int color[3];	// RGB

		for(int i = 0; i < 3; i++)
			color[i] = 0 ;

		for(int i = 0; i < n; i++)
			{
				if(colors[i] == 'R')
					color[0]++;
				else if (colors[i] == 'G')
					color[1]++;
				else
					color[2]++;
			}

		int maxval = 0;

		for(int i = 0; i < 3; i++)
		{
			if(maxval < color[i])
				maxval = color[i];
		}

		int colorchanged = n - maxval;
		cout<<colorchanged<<endl;
	}
	return 0;
}