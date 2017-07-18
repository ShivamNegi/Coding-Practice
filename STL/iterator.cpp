#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {2, 3, 4};
    vector<int> arr(a, a + sizeof(a) / sizeof(int));

/*
    Accessing the three elements in arr using iterators (pointers basically).
*/
    cout<<*(arr.begin())<<endl;

    vector<int>:: iterator it;
    it = arr.begin() + 1;
    cout<<*it<<endl;

    cout<<*(arr.end() - 1)<<endl;
    return 0;
}