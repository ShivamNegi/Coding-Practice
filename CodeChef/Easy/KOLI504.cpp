#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, d;
        cin>>n>>d;

        string one, two;
        bool flag = true;
        cin>>one>>two;
        int total_len = 0;

        for(int i = 0;; i++)
        {
            string set1, set2;
            set1 = set2 = "";
            int j = i;

            while(j < n)
            {
                set1 += one[j];
                set2 += two[j];
                j += d;
            }

            total_len += set1.length();
            sort(set1.begin(), set1.end());
            sort(set2.begin(), set2.end());

            //cout<<set1<<endl<<set2<<endl;

            if(set1 != set2)
                {
                    flag = false;
                    break;
                }

            if(total_len >= n)
                break;
        }

        if(flag)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    return 0;
}