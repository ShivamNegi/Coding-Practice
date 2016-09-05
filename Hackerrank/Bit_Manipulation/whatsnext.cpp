#include <iostream>
#include <vector>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> arr;

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            arr.push_back(no);
        }

        string inp = "";

        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                int no;
                no = arr[i];

                while(no--)
                {
                    inp = inp + '1';
                }
            }
            else
            {
                int no;
                no = arr[i];

                while(no--)
                {
                    inp = inp + '0';
                }
            }
        }
        //cout<<inp<<endl;

        int k = inp.length() - 1;

        while(inp[k] != '1')
            k--;        
    
        for(k; k >= 0; k--)
        {
            if(inp[k - 1] == '0')
            {
                inp[k] = '0';
                inp[k - 1] = '1';
                break;
            }
        }

        //cout<<inp<<endl;
        vector<int> out;
        char prev = inp[0];
        int counter = 1;

        for(int i = 1; i < inp.length(); i++)
        {
            if(prev == inp[i])
            {
                counter++;
            }
            else
            {
                out.push_back(counter);
                prev = inp[i];
                counter = 1;
            }
        }

        out.push_back(counter);
    
        cout<<out.size()<<endl;
        display(out);
    }
    return 0;
}
