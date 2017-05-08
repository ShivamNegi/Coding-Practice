#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

int k, n;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i] + 1<<" ";
    }
    cout<<endl;
}

bool fx(int x, vector<int> a)
{    
    bool flag1, flag2;
    flag1 = false;
    flag2 = false;

    if(x == n)
    {
        display(a);
        return true;
    }

    if(x > k && a[x - k] == -1)
        {
            a[x - k] = x;
            flag1 = fx(x + 1, a); 
             a[x - k] = -1;
             if(flag1){return true;}
            //flag1 = false;
        }
    if(a[x + k] == -1)
        {
            a[x + k] = x;
            flag2 = fx(x + 1, a);
            a[x + k] = -1;
            if(flag2){return true;}
            //flag2 = false;
        }

        return (flag1||flag2);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int x;
        cin>>x>>k;        

        n = x;
        vector<int> a(n);

        fill(a.begin(), a.end(), -1);
        bool res = fx(1, a);
        if(!res)cout<<"CAPTAIN AMERICA EVADES\n";
    }
    return 0;
}