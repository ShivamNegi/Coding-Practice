#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    char a[n][m];

    for(int i =0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
            cin>>a[i][j];
    }

    int t;
    cin>>t;

    for(int ik = 0; ik < t; ik++)
    {
        int l, r, c, x, y;
        cin>>l>>r>>c>>x>>y;

        r--; c--;

        switch(l)
        {
            case 1:
                    //cout<<"in\n";
                    r -= x / 2;
                    c -= y / 2;
                    for(int i = r; i < r + x; i++)
                    {
                        if(i < 0 || i >= n)
                            continue;
                        for(int j = c; j < c + y; j++)
                        {
                            if(j < 0 || j >= m)
                                continue;
                            a[i][j] = '*';
                        }
                    }
                    break;
            case 2:
                    r -= x / 2;
                    c -= y / 2;
                    for(int i = r; i < r + x; i++)
                    {
                        if(i < 0 || i >= n)
                            continue;
                        for(int j = c; j < c + y; j++)
                        {
                            if(j < 0 || j >= m)
                                continue;
                            a[i][j] = '.';
                        }
                    }
                    break;
            case 3:
                    int counter = 0;
                    r -= x / 2;
                    c -= y / 2;
                    for(int i = r; i < r + x; i++)
                    {
                        if(i < 0 || i >= n)
                            continue;
                        for(int j = c; j < c + y; j++)
                        {
                            if(j < 0 || j >= m)
                                continue;
                            if(a[i][j] == '*')
                                counter++;
                        }
                    }
                    cout<<counter<<endl;
        }

        /*for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }
        cout<<endl;*/
    }
    return 0;
}