#include <bits/stdc++.h>

class AntsMeet
{
    bool check(int x, int y, int x1, int y1)
    {
        return (x == x1 && y == y1);
    }

    void incr(vector<int> x, vector<int> y, string direction)
    {
        for(int i = 0; i < direction.length(); i++)
        {
            switch(direction[i])
            {
                case "N":
                            y[i]++;
                            break;
                case "S":
                            y[i]--;
                            break;
                case "E":
                            x[i]++;
                            break;
                case "w":
                            x[i]--;
                            break;
            }            
        }

        for(int i = 0; i < x.size(); i++)
        {
            vector<int> pos;
            pos.push_back(i);
            for(int j = i + 1; j < x.size(); j++)
            {
                if(check(x[i], y[i], x[j], y[j]))
                {
                    pos.push_back(j);
                }
            }
        }
    }

    int countAnts(vector <int> x, vector <int> y, string direction)
    {
        for(int i = 0; i < 2001; i++)
        {
            incr(x, y, direction);
        }
    }
};