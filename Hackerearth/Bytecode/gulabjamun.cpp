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

int main()
{
    int t;
    cin>>t;

    for(int k = 0; k < t; k++)
    {
        int n;
        cin>>n;
        
        vector<int> arr, rev;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
            rev.push_back(no);
        }

        sort(all(arr));
        sort(all(rev));
        reverse(all(rev));

        int high, low, highval, lowval;
        lowval = low = arr[0] + arr[1];
        highval = high = rev[0] + rev[1];

        for(int i = 2; i < n; i++)
        {
            low += arr[i];
            high += rev[i];
            highval += high;
            lowval += low;            
        }

        //cout<<highval<<"\t"<<lowval<<endl;
        cout<<"Case #"<<k+1<<": ";
        cout<<highval-lowval<<endl;
    }
    return 0;
}