#include <iostream>
#include <string>

using namespace std;

struct pair
{
    int x, y;
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int r, c;
        cin>>r>>c;

        char inp[r][c];
        for(int i = 0; i < r; i++)
        {
            string str;
            cin>>str;
            for(int j = 0; j < c; j++)
            {
                inp[i][j] = str[j];
            }
        }

        for(int i = 0; i < r; i++)
        {
            bool isnormal, left, right, top, bottom, isfree;
            isnormal = left = right = top = bottom = isfree = false;

            for(int j = 0; j < c; j++)
            {
                if(a[i][j] == 'W')
                {
                    if(i == 0 || j == 0 || i == r - 1 || j == c - 1)
                        isfree = true;
                    else
                }
            }
        }
    }
    return 0;
}