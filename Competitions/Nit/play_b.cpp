#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<endl;
}
*/

int main()
{
    int n, k;
    cin>>n>>k;

    vector<int> a;
    vector<int> b;
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        a.push_back(no);
        b.push_back(no % k);
    }

    long long size = 0;
    for(int i = 0; i <= k / 2; i++)
    {
        if(i == 0 && count(b.begin(), b.end(), 0))
            size++;
        else
        {
            int val1, val2;
            val1 = count(b.begin(), b.end(), i);
            val2 = count(b.begin(), b.end(), k - i);
            size += val1 > val2? val1: val2;
        }
    }

    cout<<size<<endl;
    return 0;
}