#include <iostream>

using namespace std;

int mdist(int pos, int l, int h)
{
    if(h - pos > pos - l)
        return h - pos;
    return pos - l;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int x, y;
        cin>>x>>y;

        char a[x][y];
        int lrow, hrow, lcol, hcol;
        lrow = x; hrow = 0;
        lcol = y; hcol = 0;
        bool flag = true;

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                cin>>a[i][j];
                if(a[i][j] == 'b')
                    flag = false;
            }
        }

        if(flag)
        {
            cout<<"0\n";
            continue;
        }

        for(int i = 0; i < x; i++)
        {
            for(int j = 0; j < y; j++)
            {
                if(a[i][j] == 'b')
                {
                    if(i < lrow)
                        lrow = i;
                    if(i > hrow)
                        hrow = i;
                    if(j < lcol)
                        lcol = j;
                    if(j > hcol)
                        hcol = j;
                }
            }
        }

        /*cout<<lrow<<"\t"<<hrow<<endl;
        cout<<lcol<<"\t"<<hcol<<endl;*/

        int posx, posy;

        posx = (hrow + lrow) / 2;
        posy = (hcol + lcol) / 2;

        int maxx, maxy;

        maxx = mdist(posx, lrow, hrow);
        maxy = mdist(posy, lcol, hcol);
        
        long long int time = 1;

        int max;

        max = maxx > maxy? maxx: maxy;

        time += (max * (max + 1) / 2);
        cout<<time<<endl;
    }

    return 0;
}