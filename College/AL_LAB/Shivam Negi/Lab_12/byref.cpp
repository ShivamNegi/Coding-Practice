#include <iostream>

using namespace std;

void incr(int a[], int size)
{
    for(int i = 0; i < size; i++)
        a[i]++;
}

void disp(int inc[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<inc[i]<<"\t";
    cout<<endl;
}

int main()
{
    int a[] = {1, 2, 3, 4};
    
    incr(a, 4);
    disp(a, 4);
    return 0;
}
