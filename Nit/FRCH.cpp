#include <iostream>
#include <vector>

using namespace std;

void display(vector<long long> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<long long> a;
        for(int i = 0; i < n; i++)
        {
            long long no;
            cin>>no;
            a.push_back(no);
        }

        long long s;
        cin>>s;

        vector<long long> out;
        int counter = 0, og_size = a.size();
        long long curr_sum = 0;

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
                {
                    curr_sum += a[0 + counter];
                    out.push_back(0 + counter + 1);
                }
            else
                {
                    curr_sum += a[og_size - 1 - counter];
                    out.push_back(og_size - counter);
                    counter++;
                }
            if(curr_sum >= s)
                break;
        }

        if(curr_sum == s)
        {
            display(out);
        }
        else
            cout<<"BING\n";
        /*cout<<curr_sum<<endl;
        display(out);*/
    }
    return 0;
}