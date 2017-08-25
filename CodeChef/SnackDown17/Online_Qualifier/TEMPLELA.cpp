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

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        bool flag = true;

        cin>>n;

        vi a;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
        }

        if(n % 2 == 0)
            flag = false;
        else
        {
            for(int i = 0; i < n; i++)        
            {
                int no;
                no = a[i];
                
                if( i <= n / 2)
                {
                    if(no != i + 1)
                    {
                        flag = false;
                        break;
                    }
                }
                else if(i > n / 2)
                {
                    if(no != n / 2 + 1 - (i - n / 2))
                    {
                        flag = false;
                        break;
                    }
                }
            }                    
        }

        if(flag)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}

