#include <iostream>
#include <map>
#include <vector>

using namespace std;

void display(map<int, int> counter)
{
    for (map<int,int>::iterator it=counter.begin(); it!=counter.end(); ++it)
        cout << it->first << " => " << it->second << '\n';
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        map<int, int> counter;
        vector<int> ini;
        int out[n];

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;

            counter[no] = 0;
        }

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;

            counter.find(no)->second++;
            ini.push_back(no);
        }

        int max_no = 0, max_val = 0;

        for (map<int,int>::iterator it=counter.begin(); it!=counter.end(); ++it)
        {
            if(it->second > max_val)
            {
                max_val = it->second;
                max_no = it->first;
            }
        }

        if(max_val > n / 2)
            {
                cout<<max_val - n / 2<<endl;   


                for(int i = 0; i < ini.size(); i ++)
                {
                    if(ini[i] != max_val)
                    {
                        out[i] = max_val;
                        max_no--;
                    }
                    else
                    {
                        if(max_no > n / 2)
                        {
                            out[i] = max_val;
                            max_no--;
                        }
                        else
                        {
                            
                        }
                    }

                }
            }
        else
            {
                cout<<"0\n";
                   
            }
    }
    return 0;
}