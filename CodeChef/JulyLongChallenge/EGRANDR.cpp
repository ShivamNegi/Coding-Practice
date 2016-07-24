#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        float no;
        cin>>no;

        bool flag = false, fullscore = false;
        float sum = 0;
        for(int i = 0;i < no; i++)
        {
            int marks;
            cin>>marks;

            if(marks == 2)
            {
                flag = true;
                break;
            }
            else
            {
                if(marks == 5)
                    fullscore = true;
                sum += marks;
            }
        }

        if(flag || !fullscore)
        {
            cout<<"No\n";
        }
        else
        {
            float avg = sum / no;
            if(avg < 4)
            {
                cout<<"No\n";
            }
            else
                cout<<"Yes\n";
        }
    }
    return 0;
}