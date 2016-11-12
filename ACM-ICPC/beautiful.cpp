#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define for_set(c, it) \
 for(typeof(c.begin()) it = c.begin(); it != c.end(); it++)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

inline void display_vi(vi a,string s)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<s;
    cout<<endl;
}

/*
    Code Here!
*/

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

        bool flag0, flag1, flag00, flag11, flagn1, flagn11;
        bool flag111, flag000;
        flag000 = flag111 = false;
        flagn1 = flagn11 = false;
        flag00 = flag11 = false;
        flag0 = flag1 = false;

        if(n == 1)
        {
            cout<<"yes\n";
            continue;
        }
        if(n > 3)
        {
            cout<<"no\n";
            continue;
        }        

        
        if(n == 2)
        {
            //hardcode
            
            //
            for(int i = 0; i < n; i++)
            {
                if(arr[i] == 0)
                {
                    if(!flag0)
                        flag0 = true;
                    else
                    {                        
                        flag00 = true;
                    }
                }
                    
                else if(arr[i] == 1)
                {
                    if(!flag1)
                    {
                        flag1 = true;
                    }
                    else
                    {
                        flag11 = true;
                    }
                }
            }

            if(!flag1 && !flag0)
            {
                cout<<"no\n";
                continue;
            }
            else
            {
                cout<<"yes\n";
                continue;
            }
        }
        if(n == 3)
        {
            for(int i = 0; i < n; i++)
            {
                if(arr[i] == 0)
                {
                    if(!flag0)
                        flag0 = true;
                    else
                    {       
                        if(!flag00)                 
                            flag00 = true;
                        else
                            flag000 = true;
                    }
                }
                    
                else if(arr[i] == 1)
                {
                    if(!flag1)
                    {
                        flag1 = true;
                    }
                    else
                    {
                        if(!flag11)                            
                            flag11 = true;
                        else
                            flag111 = true;
                    }
                }
            }

            if(!flag1)
            {
                if(flag00)
                {
                    cout<<"yes\n";
                    continue;
                }
                else
                {
                    cout<<"no\n";
                    continue;
                }                    
            }
            else if(!flag0)
            {
                if(flag11)
                {
                    cout<<"yes\n";
                    continue;
                }
                else
                {
                    cout<<"no\n";
                    continue;
                }
            }
            else
            {
                if(flag0 && flag1)
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }
        }
    }
    return 0;
}

