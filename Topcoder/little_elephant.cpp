#include <bits/stdc++.h>

using namespace std;

/*class LittleElephantAndIntervalsDiv2
{
public:
    
    
};*/

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

int getNumber(int a, vector<int> l, vector<int> r)
{
    vector<int> check_val(a);

    for(int i = 0; i < l.size(); i++)
    {
        for(int j = l[i]; j <= r[i]; j++)
        {
            check_val[j] = i + 1;
        }
    }    

    display(check_val); 
    int counter = 0;
    for(int i = 1; i < 11; i++)
    {
        if(count(check_val.begin(), check_val.end(), i) > 0)
            counter++;
    }
    return pow(2, counter);
}

void input(vector<int> &a, int m)
{
    for(int i = 0; i < m; i++)
    {
        int no;
        cin>>no;
        a.push_back(no);
    }
}



int main()
{
    int m, n;
    cin>>m;

    vector<int> l; vector<int> r;

    cin>>n;
    input(l, n);
    input(r, n);

    cout<<getNumber(m, l, r)<<endl;

    return 0;
}