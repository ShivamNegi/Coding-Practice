#include <bits/stdc++.h>
#define vs vector<string> 

using namespace std;

class MatchMaking
{
public:
    int match(string a, string b)
    {
        int val = 0;
        for(int i = 0; i < a.length(); i++)
        {
            if(a[i] == b[i])
                val++;
        }
        return val;
    }

    string makeMatch(vs nW, vs aW, vs nM, vs aM, string query)
    {
        vector<pair<string, string > > women;
        vector<pair<string, string > > men;
        vector<bool> taken;

        for(int i = 0; i < nW.size(); i++)
        {
            women.push_back(make_pair(nW[i], aW[i]));
            men.push_back(make_pair(nM[i], aM[i]));
            taken.push_back(false);
        }

        sort(women.begin(), women.end());
        sort(men.begin(), men.end());

        for(int i = 0; i < women.size(); i++)
        {
            int val = -1, pos = 0;
            for(int j = 0; j < men.size(); j++)
            {
                int temp = match(men[j].second, women[i].second);
                if(temp > val && !taken[j])
                {
                    val = temp;
                    pos = j;
                }
            }
            if(query == women[i].first)
            {
                return men[pos].first;
            }
            taken[pos] = true;
        }
    }
};

int main()
{
    
    return 0;
}