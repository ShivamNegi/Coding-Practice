#include <bits/stdc++.h>

#define vi vector<int>
#define pii pair<int, int>

using namespace std;

bool check_incline(pii a, pii b)
{
    if(a.first == b.first)
        return false;
    return true;
}

bool get_lies(pii a, pii b, pii c)
{
    bool horiz = check_incline(a, b);
    if(!horiz)
    {
        if(a.first == c.first && ((a.second - c.second) * (b.second - c.second) <= 0))
            return true;
        return false;
    }
    if(a.second == c.second && ((a.first - c.first) * (b.first - c.first) <= 0))
        return true;
    return false;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        pair<int, int> a, b;
        pair<int, int> x, y;
        int val1, val2;

        cin>>val1>>val2;
        a = make_pair(val1, val2);
        cin>>val1>>val2;
        b = make_pair(val1, val2);
        cin>>val1>>val2;
        x = make_pair(val1, val2);
        cin>>val1>>val2;
        y = make_pair(val1, val2);

        bool horiz1, horiz2;
        horiz1 = check_incline(a, b);
        horiz2 = check_incline(x, y);

        bool flag = false;
        if(horiz1 != horiz2)
        {
            if(a.first == x.first && a.second == x.second)
            {
                flag = true;
            }
            else if(b.first == x.first && b.second == x.second)
            {
                flag = true;
            }
            else if(a.first == y.first && a.second == y.second)
            {
                flag = true;
            }
            else if(b.first == y.first && b.second == y.second)
            {
                flag = true;
            }
        }
        else
        {
            flag = get_lies(a, b, x) || get_lies(a, b, y);
        }
        if(flag)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}