// Lets Memoize
#include <iostream>
#define SIZE 500

using namespace std;

long long counter = 0, fib_table[SIZE];

long long memo_recur_fib(long long n)
{
    counter++;
    if(n <= 1)
        return 1;
    else
    {
        if(fib_table[n] != -1)
            return fib_table[n];
        fib_table[n] = memo_recur_fib(n - 1) + memo_recur_fib(n - 2);
        return fib_table[n];
    }
}

long long recur_fib(long long n)
{
    if(n <= 1)
        return 1;
    else
        return recur_fib(n - 1) + recur_fib(n - 2);
}

int main()
{
    long long n;

    cout<<"Enter the number: ";
    cin>>n;

    for(long long i = 0; i < SIZE; i++)
        fib_table[i] = -1;

    cout<<memo_recur_fib(n - 1)<<endl<<endl;
    //cout<<recur_fib(n - 1)<<endl;
    //cout<<"For number: "<<n<<".The operation count is: "<<counter<<endl;
    return 0;
}