#include <iostream>

using namespace std;

void isperfect(int n)
{
    int sum = 0;

    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
            sum += i;
    }
    if(sum == n)
        cout<<"True\n";
    else
        cout<<"False\n";

}

int main()
{
    int n;
    cin>>n;
    while(n != 0)
    {
        isperfect(n);
        cin>>n;
    }
    return 0;
}