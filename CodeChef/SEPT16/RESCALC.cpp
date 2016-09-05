#include <iostream>
#include <vector>

using namespace std;

/*void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
*/

int get_bonus(int val)
{
    if(val == 4)
        return 1;
    else if(val == 5)
        return 2;
    else if(val == 6)
        return 4;
    return 0;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> values;

        for(int i = 0; i < n; i++)
        {
            int len;
            cin>>len;

            vector<int> a6(10);
            fill(a6.begin(), a6.end(), 0);
            //display(a6);

            for(int j = 0; j < len; j++)
            {
                int no;
                cin>>no;
                a6[no]++;
            }

            int uni = 0;
            for(int j = 1; j < 7; j++)
            {
                if(a6[j] > 0)
                    uni++;
            }

            values.push_back(len + get_bonus(uni));
        }

        vector<int> winners;
        int max = values[0];
        winners.push_back(1);

        for(int i = 1; i < values.size(); i++)
        {
            if(max < values[i])
            {
                max = values[i];
                winners.clear();
                winners.push_back(i + 1);
            }
            else if(max == values[i])
            {
                winners.push_back(i + 1);
            }
        }

        if(winners.size() > 1)
            cout<<"tie\n";
        else
        {
            if(winners[0] == 1)
                cout<<"chef\n";
            else
                cout<<winners[0]<<"\n";
        }
    }
    return 0;
}