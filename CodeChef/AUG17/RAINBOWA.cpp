#include <bits/stdc++.h>

using namespace std;

void display(vector<int> arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

bool exist_nos(vector<int> arr)
{
    bool val[7];
    for(int i = 0; i < 7; i++)
        val[i] = false;
    val[0] = true;

    for(int i = 0; i < arr.size(); i++)
    {
        val[arr[i]] = true;
    }

    for(int i = 0; i < 7; i++)
    {
        if(!val[i])
            return false;
    }
    return true;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int len;
        bool flag = true, seven = false;
        cin>>len;

        vector<int> arr;
        for(int i = 0; i < len; i++)
        {
            int no;
            cin>>no;
            if(no < 1 || no > 7)
                flag = false;
            if(no == 7)
                seven = true;
            arr.push_back(no);
        }

        if(!flag)
        {
            cout<<"no\n";
            continue;
        }

        vector<int> left, right;
        for(int i = 0; i < len / 2; i++)
        {
            left.push_back(arr[i]);
            right.push_back(arr[len - 1 - i]);
        }


        if(left[0] != right[0])
            flag = false;
        for(int i = 1; i < left.size(); i++)
        {
            if(left[i] < left[i - 1])
                flag = false;            
            if(right[i] < right[i - 1])
                flag = false;
            if(right[i] != left[i])
                flag = false;
            if(!flag)
                break;
        }

        if(flag && exist_nos(left) && exist_nos(right) && seven)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}