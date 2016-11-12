#include <bits/stdc++.h>

using namespace std;

/*
    Code Here!
*/

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string inp, og;

        cin>>inp;

        int len = inp.length();
        inp = inp + inp;
        int res = 0;

        for(int i = 0; i < inp.length() - len; i++)
        {
            string sub = inp.substr(i, len);
            int counter = 0;

            out.insert(sub);
        }
        cout<<out.size()<<endl;
    }
    return 0;
}

