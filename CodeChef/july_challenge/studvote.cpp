#include <iostream>
#include <vector>

using namespace std;

void clear(vector<int> a)
{
 for(int i = 0; i < a.size(); i++)
	{
		a[i] = 0;
	}
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        vector<int> inp, disq, students, votes(n + 1);

        for(int i = 0; i < n; i++)
        {
			int no;
            cin>>no;
            inp.push_back(no);
        }

		clear(votes);

		for(int i = 0; i < n; i++)
		{
			votes[inp[i]]++;
			if(inp[i] == i + 1)
				disq.push_back(inp[i]);			
		}

		for(int i = 0; i < n + 1; i++)
		{
		 if(votes[i] >= k)
			students.push_back(i);
		}
		
		int minus_counter = 0;
		for(int i = 0; i < disq.size(); i++)
		{
			for(int j = 0; j < students.size(); j++)
			{
				if(disq[i] == students[j])
					{
					 minus_counter++;
					 break;
					}
			}
		}
		cout<<students.size() - minus_counter<<endl;
    }
    return 0;
}
