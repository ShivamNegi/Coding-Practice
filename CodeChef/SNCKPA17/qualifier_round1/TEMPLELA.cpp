#include <bits/stdc++.h>
#define vi vector<int>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int len;
        vi arr;

        cin>>len;
        for(int i = 0; i < len; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        if(len % 2)
        {
            bool flag = true;
            for(int i = 0; i < len / 2; i++)
            {
                if(arr[i] != i + 1)
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false)
                cout<<"no\n";
            int counter = 0;
            for(int i = len / 2; i < len; i++)
            {
                if(arr[i] != i + 1 - counter)
                {
                    flag = false;
                    break;
                }
                counter+= 2;
            }
            if(flag)
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
        else
            cout<<"no\n";
    }
    return 0;
}