#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin>>n;

    float sum = 0;
    for(int i = 0; i < n; i++)
    {
        long long int no;
        cin>>no;
        sum += no;
    }

    cout<<floor(sum / n)<<endl;
    /*int sub = 0;
    if(sum / n - floor(sum / n) == 0.5)
        sub = 1;
    cout<<round(sum / n) - sub<<endl;*/
    return 0;
}