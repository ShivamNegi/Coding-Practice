#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        bool flag = false;
        int a[n];

        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        for(int i = 0; i < n; i++)
        {
            bool flag1 = true;
            int no = a[i];
            for(int j = i; j < i + 3; j++)
            {
                if(no != a[j])
                    {
                        flag1 = false;
                        break;
                    }
            }
            if(flag1)
            {
                flag = true;
                break;
            }
        }
        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";

    }
    return 0;
}

