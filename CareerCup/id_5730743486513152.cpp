#include <bits/stdc++.h>

using namespace std;

void permute(string base, int start, int n, map<char, vector<char> > mute, string inp)
{
    if(start == n)
        cout<<base<<endl;
    else
    {       
        char temp = base[start];
        for(int j = 0; j < mute[inp[start]].size(); j++)
        {
            base[start] = mute[inp[start]][j];
            permute(base, start + 1, n, mute, inp);
        }
        base[start] = temp;
        permute(base, start + 1, n, mute, inp);
    }
}

void display(map<char, vector<char> > mute, string inp)
{
    for(int i = 0; i < inp.length(); i++)
    {
        for(int j = 0; j < mute[inp[i]].size(); j++)
            cout<<mute[inp[i]][j]<<"\t";
        cout<<endl;
    }
}

int main()
{
    string inp;
    cin>>inp;

    int t;
    cout<<"Enter the number of mappings: ";
    cin>>t;

    map<char, vector<char> > mute;
    for(int i = 0; i < t; i++)
    {
        char ch, val;
        cin>>ch;
        cin>>val;
        mute[ch].push_back(val);
    }   

    // generating base string
    string base = "";
    for(int i = 0; i < inp.length(); i++)    
    {
        base = base + mute[inp[i]].back();
        mute[inp[i]].pop_back();
    }

    // cout<<base<<endl;
    // display(mute, inp);
    permute(base, 0, inp.length(), mute, inp);
    return 0;
}