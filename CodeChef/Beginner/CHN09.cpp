#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string colors;
        cin>>colors;

        int counta, countb;
        counta = countb = 0;

        for(int i = 0; i < colors.length(); i++)
        {
            if(colors[i] == 'a')
                counta++;
            else
                countb++;
        }

        if(counta < countb)
            cout<<counta;
        else
            cout<<countb;        
        cout<<endl;
    }
    return 0;
}