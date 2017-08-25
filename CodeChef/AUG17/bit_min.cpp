#include <bits/stdc++.h>

using namespace std;

int min(int x, int y)
{
    int x2, x3;
    x2 = x - y;
    x3 = ((x - y) >> sizeof(int ) * 8 - 1);
    cout<<x2<<"\tyay\t"<<x3<<endl;
    return y + (x2 & x3);
}

int main()
{
    int no = -4 >> 1;
    //cout<<no;
    cout<<sizeof("shivam")<<"\t"<<strlen("shivam")<<endl;
    /*while(1)
    {
        int x, y;
        cin>>x>>y;
        int res = -4 & 1;
        cout<<min(x, y)<<endl<<res<<endl;
    }*/
    return 0;
}