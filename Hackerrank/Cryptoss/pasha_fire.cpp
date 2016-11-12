#include <bits/stdc++.h>

using namespace std;

#define all(c) c.begin(), c.end()

/*
    Code Here!
*/

float min_time = INT_MAX;
vector< pair< pair<float, float> , pair<float, float> > > ships;
pair< pair<float ,float>, float> drago;

void display()
{
    for(float i = 0; i < ships.size(); i++)
    {
        cout<<ships[i].first.first<<"\t"<<ships[i].first.second<<endl;
    }
    cout<<"\n\n";
}

float distance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

float get_tan(float y, float x)
{
    return y / x;
}

float cost()
{
    float time = 0;
    float drago_x, drago_y, drago_v;

    drago_x = drago.first.first;
    drago_y = drago.first.second;
    drago_v = drago.second;

    for(float i = 0; i < ships.size(); i++)
    {
        float x, y;
        x = ships[i].first.first + ships[i].second.first * time;
        y = ships[i].first.second + ships[i].second.second * time;

        float tan_theta = get_tan(y - drago_y, x - drago_x);
        float sin_theta = tan_theta / (sqrt(1 + pow(tan_theta, 2)));
        float cos_theta = 1 / (sqrt(1 + pow(tan_theta, 2)));
        
        int tx = x + ships[i].second.first * time;
        int ty = y + ships[i].second.second * time;
        int vx, vy;
        if(abs(drago_x-x)>abs(drago_x-tx)){vx = drago_v*cos_theta + abs(ships[i].second.first); }
        else{vx = drago_v*cos_theta - abs(ships[i].second.first); }
        if(abs(drago_y-y)>abs(drago_y-ty)){vy = drago_v*sin_theta + abs(ships[i].second.second); }
        else{vy = drago_v*cos_theta - abs(ships[i].second.second); }
        
        float deno = (sqrt( pow(vx, 2) + pow(vy, 2) ));

        time += distance(x, y, drago_x, drago_y) / deno + 1;

        drago_x = ships[i].first.first + ships[i].second.first * time;
        drago_y = ships[i].first.second + ships[i].second.second * time;
    }

    time += distance(drago_x, drago_y, 0, 0)/drago_v;
    return time;
}

int main()
{
    float x, counter = 0;
    cin>>x;

    while(x != 0)
    {
        ships.erase(all(ships));

        for(float i = 0; i < x; i++)
        {
            float px, py, vx, vy;
            cin>>px>>py>>vx>>vy;
            ships.push_back(make_pair(make_pair(px, py), make_pair(vx, vy)));
        }

        sort(all(ships));        
        float px, py, v;
        cin>>px>>py>>v;

        drago = make_pair(make_pair(px, py), v);

        do
        {
            float time = cost();
            if(min_time > time)
            {
                min_time = time;
            }
        }while(next_permutation(all(ships)));

        int hrs = min_time;
        float minutesRemainder = (min_time - hrs) * 60;
        int minutes = minutesRemainder;
        float secondsRemainder = ceil(minutesRemainder - minutes) * 60;
        int seconds = secondsRemainder;

        cout<<++counter<<" "<<hrs<<" "<<minutes<<" "<<seconds<<endl;
        cin>>x;
    }
    return 0;
}
