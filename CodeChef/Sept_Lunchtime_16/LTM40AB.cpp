#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;

        if(a > b || c > d)
            cout<<"0\n";
        else
        {
            if(b < c)
            {
                ll no1 = b - a + 1;
                ll no2 = d - c + 1;
                cout<<no1*no2<<endl;
            }
            else if(b == c)
            {
                ll no1 = b - a;
                ll no2 = d - c + 1;
                cout<<no1 * no2 + (no2 - 1)<<endl;
            }
            else
            {
                if(a < c)
                {        
                    ll no1 = c - a;
                    ll no2 = d - c + 1;
                    ll sum = no1 * no2;
                    no1 = min(b, d) - c;
                    no1 = no1 * (no1 + 1) / 2;
                    sum += no1;
                    cout<<sum<<endl;
                }
                else if(a == c)
                {
                    if(b < d)
                    {
                        ll no1 = d - c;
                        no1 = no1 * (no1 + 1) / 2;
                        ll no2 = d - b - 1;
                        no2 = no2 * (no2 + 1) / 2;
                        cout<<no1 - no2<<endl;
                    }
                    else
                    {
                        ll no1 = d - c;
                        no1 = no1 * (no1 + 1) / 2;
                        cout<<no1<<endl;
                    }
                }
                else
                {
                    if(a < d)
                    {
                        if(b < d)
                        {
                            ll no1 = d - a;
                            no1 = no1 * (no1 + 1) / 2;
                            ll no2 = d - b - 1;
                            no2 = no2 * (no2 + 1) / 2;
                            cout<<no1 - no2<<endl;
                        }
                        else
                        {
                            ll no = d - a;
                            cout<<(no) * (no + 1) / 2<<endl;
                        }                        
                    }
                    else
                        cout<<"0\n";
                }
            }
        }
    }
    return 0;
}

