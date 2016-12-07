#include <iostream>

using namespace std;

void create_bad_suffix(string inp, int bad_suffix[])
{
	int lim = inp.length();
	for(int i = 0; i < 26; i++)
		bad_suffix[i] = lim;
	for(int i = 0; i < lim - 1; i++)
		bad_suffix[inp[i] - 'a'] = lim - 1 - i;
}

void create_good_suffix(string inp, int good_suffix[])
{
	int size = inp.length();

	for(int i = 1; i <= size / 2; i++)
	{
		string search = "";
		string n_inp = "";

		for(int j = 0; j < i; j++)
			search += inp[j];

		for(int  j = i; j < size; j++)
			n_inp += inp[j];

		int found = n_inp.find(search);
		if(found != string::npos)
		{
			good_suffix[i] = found + 1;
		}
		else
			good_suffix[i] = good_suffix[i - 1];

		cout<<"inp: "<<n_inp<<"\tsearch: "<<search<<"\t";
		cout<<"i: "<<i<<"\tgoodsuffix: "<<good_suffix[i]<<endl;
	}
}

void display(int a[], int size)
{
	for(int i = 0; i < size; i++)
		cout<<a[i]<<"\t";
	cout<<endl;
}

int main()
{
	string inp, sub;

	cout<<"Enter the main string: ";
	cin>>inp;

	cout<<"Enter the string to be matched: ";
	cin>>sub;

	int bad_suffix[26], good_suffix[inp.length()];

	create_bad_suffix(inp, bad_suffix);
	//display(bad_suffix, 26);

	string rev_inp = "";

	for(int i = inp.length() - 1; i >= 0; i--)
		rev_inp += inp[i];
	create_good_suffix(rev_inp, good_suffix);
	//display(bad_suffix, inp.length());

	return 0;
}
