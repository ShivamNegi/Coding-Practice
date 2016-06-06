#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

long long int mod = 1000000007;

vector<long long int> nextiter(vector<long long int> a)
{
    for(long long int k = 0; k < a.size(); k++)
        {
            if(k + 1 < a.size())
                a.insert(a.begin() + k + 1, (a[k] + a[k + 1]) % mod);
                k++;
        }
    return a;
}

vector<long long int> nextotheriter(vector<long long int> a, bool flag)
{    
    vector<long long int> temp;
    if(flag)
        for(long long int k = 1; k < a.size(); k++)
        {
            temp.push_back((a[k] + a[k - 1]) % mod);
            if(k + 1 != a.size())
                temp.push_back(a[k] % mod);
        }
    else
    {
        temp.push_back(a[0]);
        for(long long int k = 1; k < a.size(); k++)
        {
            temp.push_back((a[k] + a[k - 1]) % mod);            
            temp.push_back(a[k] % mod);
        }
    }
    return temp;
}


int main()
{
    long long int t;
    cin>>t;

    while(t--)
    {
        long long int n, m, x, y;
        cin>>n>>m>>x>>y;

        vector<long long int> a;
        vector<pair<long long int, long long int> > pos(m + 1);

        // this calculates the range of elements we need in each iteration
        pos[0].first = x; pos[0].second = y;
        for(long long int i = 1; i <= m; i++)
        {
            pos[i].first = pos[i - 1].first - (pos[i - 1].first) / 2;
            pos[i].second = pos[i - 1].second - (pos[i - 1].second - 1) / 2;
        }
        //working testcalxy.cpp

        for(long long int i = 0; i < n; i++)
        {
            long long int no;
            cin>>no;
            a.push_back(no);
        }
        
        vector<long long int> temp;
        
        for(long long int j = pos[pos.size() - 1].first - 1; j < pos[pos.size() - 1].second; j++)
        {                    temp.push_back(a[j]);                }                              
        a = temp;
        
        long long int j = 0, k = 0;
        for(j; j < m; j++)
        {                
            if(pos[pos.size() - j - 2].first == 1)
                {
                    a = nextotheriter(a, false);
                    temp.clear();
                    for(long long int pko = 0; pko < pos[pos.size() - j - 2].second; pko++)
                        {                    temp.push_back(a[pko]);                }                
                    a = temp;                            
                }
            else
                {
                    if(2 * a.size() - 1 == pos[pos.size() - j - 2].second - pos[pos.size() - j - 2].first + 1)
                    {
                        long long int temper = a[0], temper1 = a[a.size() - 1];
                        a = nextotheriter(a, true);
                        a.push_back(temper);
                        for(long long int it = a.size() - 1; it > 0; it--)
                            a[it] = a[it - 1];
                        a[0] = temper;
                        a.push_back(temper1);
                    }
                    else if(2 * a.size() - 3 == pos[pos.size() - j - 2].second - pos[pos.size() - j - 2].first + 1)
                        a = nextotheriter(a, true);
                    else if(pos[pos.size() - j - 2].first % 2 == 0)
                    {
                        long long int temper = a[a.size() - 1];
                        a = nextotheriter(a, true);
                        a.push_back(temper);
                    }
                    else
                    {
                        long long int temper = a[0];
                        a = nextotheriter(a, true);
                        a.push_back(temper);
                        for(long long int it = a.size() - 1; it > 0; it--)
                            a[it] = a[it - 1];
                        a[0] = temper;
                    }
                }
        }
        long long int sum = 0;          
        for(long long int pk = x; pk <= y; pk++)
        {           
            sum += a[pk - x] % mod;
            sum = sum % mod;
        }

        printf("%lld\n", sum);
    }
    return 0;
}
