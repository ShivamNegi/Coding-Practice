#include <bits/stdc++.h>

using namespace std;

int T, N;

int main()
{
    std::ios_base::sync_with_stdio(false);
    cin>>T;

    while(T--)
    {
        cin>>N;

        vector<int> A(N);

        for(int i=0; i<N; i++)
            cin>>A[i];
        
        long long ans=0;
        set<int> s;

        // this is the optimization of the simple logic
        // keep it simple!
        for(int i=0, j=0; i<N; i++)
        {
            // know your stl function
            // I use vector so count(a.begin(), a.end(), key)
            for(; j<N && !s.count(A[j]); j++)
                s.insert(A[j]);

            // simple formula guys! :')
            ans+=1LL*(j-i)*(j-i+1)/2;
            // take an element each time!
            s.erase(A[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}