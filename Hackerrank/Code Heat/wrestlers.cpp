#include <iostream>

using namespace std;

int main()
{
    int m, w, r;

    cin>>m>>w>>r;

    int z[m];
    int k[w];

    for(int i = 0; i < m; i++)
        z[i] = 0;

    for(int i = 0; i < r; i++)
        cin>>z[i];

    for(int i = 0; i < w; i++)
        cin>>k[i];



    return 0;
}
