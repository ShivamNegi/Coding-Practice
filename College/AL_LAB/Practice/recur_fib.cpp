#include <iostream>

using namespace std;

int counter = 0;

int recur_fib(int n)
{
    counter++;
    if(n <= 1)
        return 1;
    else
        return recur_fib(n - 1) + recur_fib(n - 2);
}

int main()
{
    int n;

    cout<<"Enter the number: ";
    cin>>n;

    cout<<recur_fib(n - 1)<<endl;
    cout<<"For number: "<<n<<".The operation count is: "<<counter<<endl;
    return 0;
}