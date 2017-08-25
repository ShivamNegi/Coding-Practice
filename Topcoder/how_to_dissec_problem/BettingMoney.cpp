#include <bits/stdc++.h>

using namespace std;

class BettingMoney
{
public:
    int moneyMade(vector<int> a, vector<int> b, int res)
    {
        int gain = 0;
        for(int i = 0; i < a.size(); i++)
        {
            if(i != res)
                gain += a[i];
        }
        int val = gain * 100 - (a[res] * b[res]);
        return val;
    }
};

int main()
{
    BettingMoney a;
    vector<int> x, y;

    for(int i = 0; i < 3; i++)
    {
        int no1, no2;
        cin>>no1>>no2;
        x.push_back(no1);
        y.push_back(no2);
    }

    cout<<a.moneyMade(x, y, 1)<<endl;
    return 0;
}