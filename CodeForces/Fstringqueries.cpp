#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void display(vector<string> inp)
{
    for(int i = 0; i < inp.size(); i++)
        cout<<inp[i]<<endl;
}

int main()
{
    int t;
    vector< string > arr;
    cin>>t;

    while(t--)
    {
        int no;
        cin>>no;
        string inp;
        cin>>inp;

        if(no == 1)
            {arr.push_back(inp);}
        else if(no == 2)
        {
            for(int i = 0; i < arr.size(); i++)
            {
                if(arr[i] == inp)
                {
                    arr.erase(arr.begin() + i);
                    break;
                }
            }
            display(arr);
        }
        else
        {
            int res = 0;
            for(int i = 0; i < arr.size(); i++)
            {
                int counter = 0;
                for(int j = 0; j < inp.length(); j++)
                {
                    counter = 0;
                    int prev = j;
                    while(arr[i][counter] == inp[j] && counter < arr[i].length())
                    {
                        counter++;
                        j++;
                    }
                    if(counter == arr[i].length())
                        res++;
                    j = prev;
                }
            }
            cout<<res<<endl;
        }

    }
    return 0;
}