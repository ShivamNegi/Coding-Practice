#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int len, q;
        cin>>len>>q;

        vi arr;
        for(int i = 0; i < len; i++)        
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        sort(arr.begin(), arr.end());

        while(q--)
        {
            int no, pos = 0;
            cin>>no;

            for(pos = 0; pos < len; pos++)
            {
                if(arr[pos] > no)
                    break;
            }

            pos--;
            int snakes_left = pos, counter = len - pos - 1;

            for(int j = pos; j >= 0; j--)
            {
                int eat = no - arr[j];
                if(eat < snakes_left)
                {
                    counter++;
                    snakes_left -= eat;
                }
                else
                    break;
                snakes_left--;
            }
            cout<<counter<<endl;
        }
    }
    return 0;
}