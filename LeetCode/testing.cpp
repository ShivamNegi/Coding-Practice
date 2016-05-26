#include<bits/stdc++.h>

using namespace std;

int main()
{
    string ops;
    cin>>ops;
    cout<<sizeof(ops)<<endl;

    ops = ops + ops + ops;

    cout<<ops<<sizeof(ops)<<endl;
    //how to find N+1 permutations of n characters 
    sort(ops.begin(), ops.end());

    do
    {
        cout<<ops.substr(0, 3)<<"\n";
    }while( next_permutation(ops.begin(), ops.end()) );

    if(ops[0] == '+')
            {
                cout<<"Plus is encountered.";
            }
            else if(ops[1] == '-')
            {
                cout<<"Minus is encountered.";
            }
            else
            {
                cout<<"Multiplication is encountered.";
            }
    cout<<endl;            

    return 0;
}