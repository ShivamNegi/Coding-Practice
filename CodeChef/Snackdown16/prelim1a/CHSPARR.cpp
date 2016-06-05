#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void display(vector<int> a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void displaypair(vector<pair<int, int> > a)
{
    for(int i = 0; i < a.size(); i++)
    {
        cout<<a[i].first<<" "<<a[i].second<<endl;
    }

}

vector<int> nextiter(vector<int> a)
{
    for(int k = 0; k < a.size(); k++)
        {
            if(k + 1 < a.size())
                a.insert(a.begin() + k + 1, a[k] + a[k + 1]);
                k++;
        }
    return a;
}

vector<int> nextotheriter(vector<int> a, bool flag)
{    
    vector<int> temp;
    if(flag)
        for(int k = 1; k < a.size(); k++)
        {
            temp.push_back(a[k] + a[k - 1]);
            if(k + 1 != a.size())
                temp.push_back(a[k]);
        }
    else
    {
        temp.push_back(a[0]);
        for(int k = 1; k < a.size(); k++)
        {
            temp.push_back(a[k] + a[k - 1]);            
            temp.push_back(a[k]);
        }
    }
    return temp;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, m, x, y;
        cin>>n>>m>>x>>y;

        vector<int> a, temp;
        vector<pair<int, int> > pos(m + 1);

        // this calculates the range of elements we need in each iteration
        pos[0].first = x; pos[0].second = y;
        for(int i = 1; i <= m; i++)
        {
            pos[i].first = pos[i - 1].first - (pos[i - 1].first) / 2;
            pos[i].second = pos[i - 1].second - (pos[i - 1].second - 1) / 2;
        }
        //working testcalxy.cpp

        for(int i = 0; i < n; i++)
        {
            int no;
            cin>>no;
            a.push_back(no);
        }
        
        for(int i = 0; i < m; i++)
        {
            if(a.size() < pos[pos.size() - 1 - i].second)
            {
                a = nextiter(a);                
                if(i + 1 == m)
                {
                    for(int j = pos[pos.size() - i - 1].first - 1; j < pos[pos.size() - i - 1].second; j++)
                        {                    temp.push_back(a[j]);                }
                    a = temp;
                }
            }
            else
            {
                // find the number of iterations left
                // form the first curr iteration to the last iteration
                // jot down what all positions do I need
                // then only calculate those position only 
                // the final result will be the sum of the resulting array
                vector<int> temp;

                display(a);
                for(int j = pos[pos.size() - i - 1].first - 1; j < pos[pos.size() - i - 1].second; j++)
                {                    temp.push_back(a[j]);                }                              
                a = temp;
                display(a);
                
                int j = i, k = 0;
                for(j; j < m; j++)
                {                
                    if(pos[pos.size() - j - 2].first == 1)
                        {
                            a = nextotheriter(a, false);
                            cout<<"segment:"<<pos[pos.size() - j - 2].second<<"\t";
                            //display(a);
                            temp.clear();
                            for(int pko = 0; pko < pos[pos.size() - j - 2].second; pko++)
                                {                    temp.push_back(a[pko]);                }
                            //cout<<"temp";
                            //display(temp);
                            a = temp;                            
                        }
                    else
                        {
                            if(2 * a.size() - 3 == pos[pos.size() - j - 2].second - pos[pos.size() - j - 2].first + 1)
                                a = nextotheriter(a, true);
                            else if(pos[pos.size() - j - 2].first % 2 == 0)
                            {
                                int temper = a[a.size() - 1];
                                a = nextotheriter(a, true);
                                a.push_back(temper);
                            }
                            else
                            {
                                int temper = a[0];
                                a = nextotheriter(a, true);
                                a.push_back(temper);
                                for(int it = a.size() - 1; it > 0; it--)
                                    a[it] = a[it - 1];
                                a[0] = temper;
                            }


                        }
                    display(a);
                }
                break;
            }
        }
        //display(a);
        long int sum = 0;
        for(int pk = x; pk <= y; pk++)
        {
            sum += a[pk - x];
        }
        cout<<sum<<endl;
    }
    return 0;
}
