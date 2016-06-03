#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin>>n>>m>>k;

    string s, t;
    if(n < m)
    {
        cin>>s;
        cin>>t;   
    }
    else
    {
        cin>>t;
        cin>>s;        
    }

    for(int i = 0; i < t.length(); i++)
    {
        int cost = 0;
        for(int j = 0; j < s.length(); j++)
        {
            int val = int(t[i + j] - s[j]) ;
            if(val >13)
            {
                cost += (26 - val);
            }
            else
            {
                cost += val;
            }
        }
        if(cost < k)
        {
            cout<<cost;
            break;
        }
    }
    
    return 0;
}