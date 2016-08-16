#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}*/

int main()
{
    int n;
    cin>>n;

    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int no;
        cin>>no;
        a.push_back(no);
    }

    sort(a.begin(), a.end());
    /*display(a);*/
    long long int max = 0, prev = a[0], count = 1;
    for(int i = 1; i < a.size(); i++)
        {
        if(prev == a[i])
            {
            count++;
        }
        else
            {
            prev = a[i];
            if(count > max)
                max = count;
            count = 1;
        }
    }
    if(count > max)
        max = count;
    cout<<max<<endl;
    return 0;
}