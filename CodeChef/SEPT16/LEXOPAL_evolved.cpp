#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void clear(int alpha[], int size)
{
    for(int i = 0; i < size; i++)
        alpha[i] = 0;
}

int odd_occurs(int alpha[], int size)
{
    int res = 0;
    for(int i = 0; i < size; i++)
    {
        if(alpha[i] % 2 != 0)
            res++;
    }
    return res;
}

int main()
{
 int t;
 cin>>t;

 while(t--)
    {
        int alpha[26], any = 0;
        string inp;
        cin>>inp;

        clear(alpha, 26);
        for(int i = 0; i < inp.length(); i++)
        {
            if(inp[i] == '.')
                any++;
            else
                alpha[inp[i] - 'a']++;
        }

        int uneven = odd_occurs(alpha, 26);

        if(uneven > any)
            {
                cout<<"-1\n";
                continue;
            }

        string out = "";
        int az = any - uneven, middle;
        if(az % 2 != 0)
            middle = 1;
        for(int i = 0; i < az / 2; i++)
            out = out + 'a';

        cout<<out<<endl;
        string order = "";
        for(int i = 0; i < 26; i++)
        {
            if(alpha[i] % 2 != 0)
            {
                for(int j = 0; j < alpha[i] / 2 + 1; j++)
                    order += char(alpha[i]);
            }
            else
                for(int j = 0; j < alpha[i] / 2; j++)
                    order += char(alpha[i]);
        }
        out += order;
        if(middle)
            out += 'a';
        reverse(order.begin(), order.end());
        out += order;
        cout<<out<<endl;
    }
 return 0;
}