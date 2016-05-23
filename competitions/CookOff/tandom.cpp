#include<bits/stdc++.h>

using namespace std;

bool isTandom(string inp)
{
	int l = inp.length();
	int size = l / 3;

	if(inp.substr(0, size).compare(inp.substr(size, size)) == 0)
		if(inp.substr(size, size).compare(inp.substr(2 * size, size) ) == 0)
			return true;

	return false;	

}

int main()
{
	string inp;
	cin>>inp;

	int countint, countbore;
	countint = countbore = 0;

	for(int i = 0; i < inp.length() - 2; i++)
	{
		for(int j = 1; j * 3 <= inp.length() - i; j ++)
		{			
			if (isTandom(inp.substr(i, j * 3)))
			{
				if (j + 2 > inp.length())
					countint++;
				else if (inp[i] != inp[i + j * 3])
					countint++;
				else
					countbore++;
			}
		}
	}

	cout<<countint<<" "<<countbore<<endl;
	return 0;	
}