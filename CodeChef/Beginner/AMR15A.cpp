#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> even, odd;

    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;

        if(no % 2 == 0)
            even.push_back(no);
        else
            odd.push_back(no);
    }

    if(even.size() > odd.size())
        cout<<"READY FOR BATTLE\n";
    else
        cout<<"NOT READY\n";
    return 0;
}