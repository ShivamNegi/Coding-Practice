#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

/*
    Code Here!
*/

class AlmostPerfectNumber
{
    int s(int a)
{
    int suma = 0;
    for(int i = 1; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            if(a / i != i)
                suma += i + a / i;
            else
                suma += i;
        }
    }
    return suma;
}

 int count(int l, int r, int k)
 {
    int counter = 0;

    for(int i = l; i <= r; i ++)
    {
        if(abs(i - s(i)) <= k)
            counter++;
    }
    return counter;    
 }


};


/*int main()
{
    int l, r, k;
    cin>>l>>r>>k;

    int counter = 0;

    for(int i = l; i <= r; i ++)
    {
        if(abs(i - s(i)) <= k)
            counter++;
    }

    cout<<counter<<endl;
    return 0;
}
*/
