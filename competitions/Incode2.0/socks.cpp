#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, d;
        cin>>n>>d;

        vector<int> a;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
        }

        sort(a.begin(), a.end());

        int counter = 0;

        for(int i = 0; i < n; i++)
        {
            if(a[i + 1] - a[i] > d)
                counter++;
            i++;
        }

        cout<<counter<<endl;
    }

    return 0;
}