#include <iostream>
#include <cmath>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long n, q;
    cin>>n>>q;
    /*scanf(" %d %d", &n, &q);*/

    vector<long long> a;
    int prev = 0;
    for(long long i = 0; i < n; i++)
    {
        long long no;
        cin>>no;
        /*scanf(" %d", &no);*/
        no = floor(log2(no)) + 1;
        prev += no;
        a.push_back(prev);
    }

    for(long long i = 0; i < q; i++)
    {
        long long x, y;

        cin>>x>>y;
        /*scanf(" %d %d", &x, &y);*/

        long long val;
        if(x == 1)
            val = a[y - 1];
        else
            val = a[y - 1] - a[x - 2];
        
        if(val % 2 == 0)
            cout<<"Hacker\n";            
            /*printf("Hacker\n");*/
        else
            cout<<"Mishki\n";
            /*printf("Mishki\n");*/
    }

    return 0;
}