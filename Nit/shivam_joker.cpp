#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int r, c;
    cin>>r>>c;

    vector<long long> inp(r)(c);
    long long sum = 0;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            cin>>inp[i][j];
            sum += inp[i][j];
            
        }
    }
}