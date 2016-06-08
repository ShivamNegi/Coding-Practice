#include <iostream>
#include <vector>

using namespace std;

vector<int> multiply(int no, vector<int> a)
{
    int carry = 0;
    for(int i = 0; i < a.size(); i++)
    {
        int prod = a[i] * no + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }

    while(carry)
    {
        a.push_back(carry % 10);
        carry /= 10;
    }

    return a;
}

void factorial(int no)
{
    std::vector<int> a;
    a.push_back(1);
    for(int i = 1; i <= no; i++)
    {
        a = multiply(i, a)        ;
    }

    for(int i = a.size() - 1; i >= 0; i--)
    {
        cout<<a[i];
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        factorial(n);
    }
    return 0;
}