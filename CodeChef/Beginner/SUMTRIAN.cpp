#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    int t;
    scanf("%d", &t);

    while(t--)
    {
        int n;
        scanf("%d", &n);

        vector<int> a;

        for(int i = 0; i < n * (n + 1) / 2; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
        }

        display(a);
        vector<int> inp;
        // int inp[n * (n + 1) / 2];

        inp.push_back(a[0]);

        for(int i = 1; i < n; i++)
        {
            int pos = i * (i + 1) / 2;
            for(int j = 0; j < i; j++)
            {
                inp.push_back(a[pos + j]);
                j++;
                inp.push_back(a[pos + j]);
                if(j != i)
                    j--;
            }
        }
        display(inp);
    }

    return 0;
}